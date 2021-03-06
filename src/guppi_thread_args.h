#ifndef _GUPPI_THREAD_ARGS_H
#define _GUPPI_THREAD_ARGS_H
/* Generic thread args type with input/output buffer
 * id numbers.  Not all threads have both a input and a
 * output.
 */
#include <pthread.h>
#include <sys/time.h>
#include <math.h>
struct guppi_thread_args {
    int input_buffer;
    int output_buffer;
    int priority;
    int finished;
    pthread_cond_t finished_c;
    pthread_mutex_t finished_m;
};
void guppi_thread_args_init(struct guppi_thread_args *a);
void guppi_thread_args_destroy(struct guppi_thread_args *a);
void guppi_thread_set_finished(struct guppi_thread_args *a);
int guppi_thread_finished(struct guppi_thread_args *a, 
        float timeout_sec);
#endif
