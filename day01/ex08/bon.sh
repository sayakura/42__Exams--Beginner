#! /bin/bash
ldapsearch -Q -H ldap://ldap-master.42.us.org "sn=*bon*" | grep "sn: " | grep "bon" | wc -l | sed "s/[[:space:]]//g"
