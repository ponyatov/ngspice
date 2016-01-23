rem invoke as
rem    .\try.bat analog

set sub=%1

set CMPP_IDIR=../../src/xspice/icm/%sub%
set CMPP_ODIR=icm/%sub%
if not exist icm\%sub% mkdir icm\%sub%
.\bin\cmpp -lst

for %%n in (
  climit divide d_dt gain hyst ilimit int limit
  mult multi_input_pwl oneshot pwl sine slew
  square summer s_xfer triangle file_source
) do (
  set CMPP_IDIR=..\..\src\xspice\icm\%sub%\%%n
  set CMPP_ODIR=icm\%sub%\%%n
  if not exist icm\%sub%\%%n mkdir icm\%sub%\%%n
  .\bin\cmpp -ifs
  .\bin\cmpp -mod
  pushd icm\%sub%\%%n
  if exist %%n-cfunc.c del %%n-cfunc.c
  if exist %%n-ifspec.c del %%n-ifspec.c
  rename cfunc.c %%n-cfunc.c
  rename ifspec.c %%n-ifspec.c
  popd
)

