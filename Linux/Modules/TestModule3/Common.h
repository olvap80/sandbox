//
#include <linux/kernel.h>

///Runtime check for Kernel with severity and action attached
/** Customizable "soft" alternative for BUG_ON and WARN_ON to provide more info
 and to allow more flexible handling in situation when it is possible to
 continue execution without reset.
 @param cond condition to check (and to print on failure).
 @param level corresponds to KERN_*level* as passed to printk (see
 http://lxr.free-electrons.com/source/include/linux/kern_levels.h for details).
 @param action what to do when condition failed (note: one has to do the most to
 restore/continue execution/bubble up the problem instead of causeing reset). */
#define CHECKED(cond, level, action) \
	if( unlikely(!(cond)) ) \
		{ printk(KERN_##level "%s:%d: %s: Assertion '%s' failed.\n", \
		__FILE__,__LINE__,__func__, #cond); action; } \
	else ((void)0)

//CHECKED( t < timeout, INFO, goto Error);