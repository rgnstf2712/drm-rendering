#ifndef MYSESSION_H
#define MYSESSION_H

#include <systemd/sd-bus.h>

struct session_info_t {
	char *id;
	unsigned int vt;
	char *seat;
	sd_bus *bus;
	char *object;
	sd_bus_message *TD_msg; //TODO: find better solution
};

void get_boot_gpu(int *major, int *minor);

struct session_info_t *create_session_info();
int destroy_session_info(struct session_info_t *session_info);

int take_control(struct session_info_t *session_info);
int release_control(struct session_info_t *session_info);

int take_device(struct session_info_t *session_info, int major, int minor);
int release_device(struct session_info_t *session_info, int fd);

#endif