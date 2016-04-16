#include "ngspice/ngspice.h"
#include "ngspice/iferrmsg.h"

#include "ngspice/evt.h"
#include "ngspice/evtproto.h"


static void Evt_State_Data_destroy(Evt_Ckt_Data_t *evt, Evt_State_Data_t *state_data);


static void
Evt_Node_destroy(Evt_Node_Info_t *info, Evt_Node_t *node)
{
    tfree(node->node_value);
    tfree(node->inverted_value);

    if (node->output_value) {
        int k = info->num_outputs;
        while (--k >= 0)
            tfree(node->output_value[k]);
        tfree(node->output_value);
    }
}


static void
Evt_Node_Data_destroy(Evt_Ckt_Data_t *evt, Evt_Node_Data_t *node_data)
{
    int i;

    if (!node_data)
        return;

    for (i = 0; i < evt->counts.num_nodes; i++) {
        Evt_Node_Info_t *info = evt->info.node_table[i];
        Evt_Node_t *node;
        node = node_data->head[i];
        while (node) {
            Evt_Node_t *next = node->next;
            Evt_Node_destroy(info, node);
            tfree(node);
            node = next;
        }
        node = node_data->free[i];
        while (node) {
            Evt_Node_t *next = node->next;
            Evt_Node_destroy(info, node);
            tfree(node);
            node = next;
        }
    }
    tfree(node_data->head);
    tfree(node_data->tail);
    tfree(node_data->last_step);
    tfree(node_data->free);

    tfree(node_data->modified);
    tfree(node_data->modified_index);

    for (i = 0; i < evt->counts.num_nodes; i++) {
        Evt_Node_Info_t *info = evt->info.node_table[i];
        Evt_Node_destroy(info, &(node_data->rhs[i]));
        Evt_Node_destroy(info, &(node_data->rhsold[i]));
    }

    tfree(node_data->rhs);
    tfree(node_data->rhsold);
    tfree(node_data->total_load);
}


static void
Evt_Msg_Data_destroy(Evt_Ckt_Data_t *evt, Evt_Msg_Data_t *msg_data)
{
    int i;

    if (!msg_data)
        return;

    for (i = 0; i < evt->counts.num_ports; i++) {
        Evt_Msg_t *msg;
        msg = msg_data->head[i];
        while (msg) {
            Evt_Msg_t *next = msg->next;
            if (msg->text)
                tfree(msg->text);
            tfree(msg);
            msg = next;
        }
        msg = msg_data->free[i];
        while (msg) {
            Evt_Msg_t *next = msg->next;
            if (msg->text)
                tfree(msg->text);
            tfree(msg);
            msg = next;
        }
    }

    tfree(msg_data->head);
    tfree(msg_data->tail);
    tfree(msg_data->last_step);
    tfree(msg_data->free);

    tfree(msg_data->modified);
    tfree(msg_data->modified_index);
}


int
EVTdest(Evt_Ckt_Data_t *evt)
{
    int i;

    /* Get temporary pointers for fast access */
    Evt_Output_Queue_t  *output_queue;
    Evt_Node_Queue_t    *node_queue;
    Evt_Inst_Queue_t    *inst_queue;

    Evt_State_Data_t    *state_data;

    /* Exit immediately if no event-driven instances in circuit */
    if (evt->counts.num_insts == 0)
        return(OK);

    output_queue = &(evt->queue.output);
    node_queue = &(evt->queue.node);
    inst_queue = &(evt->queue.inst);

    state_data = evt->data.state;

    /* instance queue */
    for (i = 0; i < evt->counts.num_insts; i++) {
        Evt_Inst_Event_t *event = inst_queue->head[i];
        while (event) {
            Evt_Inst_Event_t *next = event->next;
            tfree(event);
            event = next;
        }
    }
    tfree(inst_queue->head);
    tfree(inst_queue->current);
    tfree(inst_queue->last_step);
    tfree(inst_queue->free);

    tfree(inst_queue->modified_index);
    tfree(inst_queue->modified);
    tfree(inst_queue->pending_index);
    tfree(inst_queue->pending);
    tfree(inst_queue->to_call_index);
    tfree(inst_queue->to_call);

    /* node queue */

    tfree(node_queue->to_eval_index);
    tfree(node_queue->to_eval);
    tfree(node_queue->changed_index);
    tfree(node_queue->changed);

    /* output queue */
    for (i = 0; i < evt->counts.num_outputs; i++) {
        Evt_Output_Event_t *event;
        event = output_queue->head[i];
        while (event) {
            Evt_Output_Event_t *next = event->next;
            tfree(event->value);
            tfree(event);
            event = next;
        }
        event = output_queue->free[i];
        while (event) {
            Evt_Output_Event_t *next = event->next;
            tfree(event->value);
            tfree(event);
            event = next;
        }
    }
    tfree(output_queue->head);
    tfree(output_queue->current);
    tfree(output_queue->last_step);
    tfree(output_queue->free);

    tfree(output_queue->modified_index);
    tfree(output_queue->modified);
    tfree(output_queue->pending_index);
    tfree(output_queue->pending);
    tfree(output_queue->changed_index);
    tfree(output_queue->changed);

    Evt_State_Data_destroy(evt, state_data);
    Evt_Node_Data_destroy(evt, evt->data.node);
    Evt_Msg_Data_destroy(evt, evt->data.msg);

    tfree(evt->data.node);
    tfree(evt->data.state);
    tfree(evt->data.msg);
    tfree(evt->data.statistics);

    for (i = 0; i < evt->jobs.num_jobs; i++)
        tfree(evt->jobs.job_name[i]);
    tfree(evt->jobs.job_name);
    tfree(evt->jobs.node_data);
    tfree(evt->jobs.state_data);
    tfree(evt->jobs.msg_data);
    tfree(evt->jobs.statistics);

    tfree(evt->info.hybrid_index);

    Evt_Inst_Info_t *inst = evt->info.inst_list;
    while (inst) {
        Evt_Inst_Info_t *next_inst = inst->next;
        tfree(inst);
        inst = next_inst;
    }
    tfree(evt->info.inst_table);

    Evt_Node_Info_t *nodei = evt->info.node_list;
    while (nodei) {
        Evt_Node_Info_t *next_nodei = nodei->next;
        tfree(nodei->name);

        Evt_Inst_Index_t *p = nodei->inst_list;
        while (p) {
            Evt_Inst_Index_t *next_p = p->next;
            tfree(p);
            p = next_p;
        }

        tfree(nodei);
        nodei = next_nodei;
    }
    tfree(evt->info.node_table);

    Evt_Port_Info_t *port = evt->info.port_list;
    while (port) {
        Evt_Port_Info_t *next_port = port->next;
        tfree(port->node_name);
        tfree(port->inst_name);
        tfree(port->conn_name);
        tfree(port);
        port = next_port;
    }
    tfree(evt->info.port_table);

    Evt_Output_Info_t *output = evt->info.output_list;
    while (output) {
        Evt_Output_Info_t *next_output = output->next;
        tfree(output);
        output = next_output;
    }
    tfree(evt->info.output_table);

    return(OK);
}


static void
Evt_State_Data_destroy(Evt_Ckt_Data_t *evt, Evt_State_Data_t *state_data)
{
    int i;

    if (!state_data)
        return;

    for (i = 0; i < evt->counts.num_insts; i++) {
        Evt_State_t *state = state_data->head[i];
        while (state) {
            Evt_State_t *next = state->next;
            tfree(state->block);
            tfree(state);
            state = next;
        }
    }

    tfree(state_data->head);
    tfree(state_data->tail);
    tfree(state_data->last_step);
    tfree(state_data->free);

    tfree(state_data->modified);
    tfree(state_data->modified_index);
    tfree(state_data->total_size);

    for (i = 0; i < evt->counts.num_insts; i++) {
        Evt_State_Desc_t *p = state_data->desc[i];
        while (p) {
            Evt_State_Desc_t *next_p = p->next;
            tfree(p);
            p = next_p;
        }
    }

    tfree(state_data->desc);
}
