X(volatile jiffy_t jiffies, (jiffy_t)(-3 * HZ));
X(volatile U8 time_slice, 0);
X(struct dlist sleeping_queue, DLIST_INIT(sleeping_queue));
X(struct dlist running_queue, DLIST_INIT(running_queue));
X(struct dlist * volatile current_task, NULL);
X(U16 * volatile stack_pointer, NULL);
