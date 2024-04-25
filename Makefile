all:
# For Ubuntu apt-get install install libpam0g-dev
# For fedora yum install pam-devel
	gcc -fPIC -lcurl -c myauth.c
	ld -x --shared -o ld -x --shared -o /lib/x86_64-linux-gnu/security/pam_myauth.so myauth.o
