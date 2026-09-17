# 3주차 2차시

> 수업 날짜: `2026-09-16`

## 실습 기록

- 환경: `Ubuntu WSL 26.04 LTS`

### 실습 1. 실습 디렉터리 만들기

#### 실행한 명령어와 결과

```console
$ cd
$ pwd
/home/user
$ mkdir linux
```

홈 디렉터리에서 `linux` 실습 디렉터리를 만들었다.

---

### 실습 2. 실습 디렉터리로 이동하여 경로 확인하기

#### 실행한 명령어와 결과

```console
$ cd linux
$ pwd
/home/user/linux
```

`cd linux`로 실습 디렉터리로 이동한 뒤 `pwd`로 현재 경로를 확인했다.

---

### 실습 3. ch03 서브디렉터리 만들고 이동하여 경로 확인하기

#### 실행한 명령어와 결과

```console
$ mkdir ch03
$ ls -asl
total 12
4 drwxr-xr-x 3 user user 4096 Sep 16 17:05 .
4 drwxr-x--- 8 user user 4096 Sep 16 17:04 ..
4 drwxr-xr-x 2 user user 4096 Sep 16 17:05 ch03
$ cd ch03
$ pwd
/home/user/linux/ch03
```

`ch03` 디렉터리를 만들고, 목록과 현재 경로를 확인했다.

---

### 실습 4. 파일을 만들고 확인하기

#### 실행한 명령어와 결과

```console
$ cat > test.txt
 테스트 파일 만들기
$ ls -l
total 4
-rw-r--r-- 1 user user 29 Sep 16 17:05 test.txt
```

`cat > test.txt`로 입력한 내용을 파일로 저장하고, `ls -l`로 파일 생성과 크기를 확인했다.

---

### 실습 5. 부모 디렉터리로 이동하면서 경로 확인하기

#### 실행한 명령어와 결과

```console
$ cd ..
$ pwd
/home/user/linux
$ cd ..
$ pwd
/home/user
```

`cd ..`를 두 번 실행하여 상위 디렉터리로 이동하는 방법을 확인했다.

---

### 실습 6. /etc/services 파일을 살펴보자

#### 실행한 명령어와 결과

```console
$ ls -sl /etc/services
16 -rw-r--r-- 1 root root 12990 Mar 16  2025 /etc/services
```

`ls -sl`로 `/etc/services`의 디스크 블록 수와 상세 정보를 확인했다.

---

### 실습 7. /etc/services의 내용을 출력한다

#### 실행한 명령어

```console
$ cat /etc/services
```

#### 실행 결과

```text
# Network services, Internet style
#
# Updated from https://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.xhtml .
#
# New ports will be added on request if they have been officially assigned
# by IANA and used in the real-world or are needed by a debian package.
# If you need a huge list of used numbers please install the nmap package.

tcpmux          1/tcp                           # TCP port service multiplexer
echo            7/tcp
echo            7/udp
discard         9/tcp           sink null
discard         9/udp           sink null
systat          11/tcp          users
daytime         13/tcp
daytime         13/udp
netstat         15/tcp
qotd            17/tcp          quote
chargen         19/tcp          ttytst source
chargen         19/udp          ttytst source
ftp-data        20/tcp
ftp             21/tcp
fsp             21/udp          fspd
ssh             22/tcp                          # SSH Remote Login Protocol
telnet          23/tcp
smtp            25/tcp          mail
time            37/tcp          timserver
time            37/udp          timserver
whois           43/tcp          nicname
tacacs          49/tcp                          # Login Host Protocol (TACACS)
tacacs          49/udp
domain          53/tcp                          # Domain Name Server
domain          53/udp
bootps          67/udp
bootpc          68/udp
tftp            69/udp
gopher          70/tcp                          # Internet Gopher
finger          79/tcp
http            80/tcp          www             # WorldWideWeb HTTP
kerberos        88/tcp          kerberos5 krb5 kerberos-sec     # Kerberos v5
kerberos        88/udp          kerberos5 krb5 kerberos-sec     # Kerberos v5
iso-tsap        102/tcp         tsap            # part of ISODE
acr-nema        104/tcp         dicom           # Digital Imag. & Comm. 300
pop3            110/tcp         pop-3           # POP version 3
sunrpc          111/tcp         portmapper      # RPC 4.0 portmapper
sunrpc          111/udp         portmapper
auth            113/tcp         authentication tap ident
nntp            119/tcp         readnews untp   # USENET News Transfer Protocol
ntp             123/udp                         # Network Time Protocol
epmap           135/tcp         loc-srv         # DCE endpoint resolution
netbios-ns      137/udp                         # NETBIOS Name Service
netbios-dgm     138/udp                         # NETBIOS Datagram Service
netbios-ssn     139/tcp                         # NETBIOS session service
imap2           143/tcp         imap            # Interim Mail Access P 2 and 4
snmp            161/tcp                         # Simple Net Mgmt Protocol
snmp            161/udp
snmp-trap       162/tcp         snmptrap        # Traps for SNMP
snmp-trap       162/udp         snmptrap
cmip-man        163/tcp                         # ISO mgmt over IP (CMOT)
cmip-man        163/udp
cmip-agent      164/tcp
cmip-agent      164/udp
mailq           174/tcp                 # Mailer transport queue for Zmailer
xdmcp           177/udp                 # X Display Manager Control Protocol
bgp             179/tcp                         # Border Gateway Protocol
smux            199/tcp                         # SNMP Unix Multiplexer
qmtp            209/tcp                         # Quick Mail Transfer Protocol
z3950           210/tcp         wais            # NISO Z39.50 database
ipx             213/udp                         # IPX [RFC1234]
ptp-event       319/udp
ptp-general     320/udp
pawserv         345/tcp                         # Perf Analysis Workbench
zserv           346/tcp                         # Zebra server
rpc2portmap     369/tcp
rpc2portmap     369/udp                         # Coda portmapper
codaauth2       370/tcp
codaauth2       370/udp                         # Coda authentication server
clearcase       371/udp         Clearcase
ldap            389/tcp                 # Lightweight Directory Access Protocol
ldap            389/udp
svrloc          427/tcp                         # Server Location
svrloc          427/udp
https           443/tcp                         # http protocol over TLS/SSL
https           443/udp                         # HTTP/3
snpp            444/tcp                         # Simple Network Paging Protocol
microsoft-ds    445/tcp                         # Microsoft Naked CIFS
kpasswd         464/tcp
kpasswd         464/udp
submissions     465/tcp         ssmtp smtps urd # Submission over TLS [RFC8314]
saft            487/tcp                 # Simple Asynchronous File Transfer
isakmp          500/udp                         # IPSEC key management
rtsp            554/tcp                 # Real Time Stream Control Protocol
rtsp            554/udp
nqs             607/tcp                         # Network Queuing system
asf-rmcp        623/udp         # ASF Remote Management and Control Protocol
qmqp            628/tcp
ipp             631/tcp                         # Internet Printing Protocol
ldp             646/tcp                         # Label Distribution Protocol
ldp             646/udp
#
# UNIX specific services
#
exec            512/tcp
biff            512/udp         comsat
login           513/tcp
who             513/udp         whod
shell           514/tcp         cmd syslog      # no passwords used
syslog          514/udp
printer         515/tcp         spooler         # line printer spooler
talk            517/udp
ntalk           518/udp
route           520/udp         router routed   # RIP
gdomap          538/tcp                         # GNUstep distributed objects
gdomap          538/udp
uucp            540/tcp         uucpd           # uucp daemon
klogin          543/tcp                         # Kerberized `rlogin' (v5)
kshell          544/tcp         krcmd           # Kerberized `rsh' (v5)
dhcpv6-client   546/udp
dhcpv6-server   547/udp
afpovertcp      548/tcp                         # AFP over TCP
nntps           563/tcp         snntp           # NNTP over SSL
submission      587/tcp                         # Submission [RFC4409]
ldaps           636/tcp                         # LDAP over SSL
ldaps           636/udp
tinc            655/tcp                         # tinc control port
tinc            655/udp
silc            706/tcp
kerberos-adm    749/tcp                         # Kerberos `kadmin' (v5)
#
domain-s        853/tcp                         # DNS over TLS [RFC7858]
domain-s        853/udp                         # DNS over DTLS [RFC8094]
rsync           873/tcp
ftps-data       989/tcp                         # FTP over SSL (data)
ftps            990/tcp
telnets         992/tcp                         # Telnet over SSL
imaps           993/tcp                         # IMAP over SSL
pop3s           995/tcp                         # POP-3 over SSL
#
# From ``Assigned Numbers'':
#
#> The Registered Ports are not controlled by the IANA and on most systems
#> can be used by ordinary user processes or programs executed by ordinary
#> users.
#
#> Ports are used in the TCP [45,106] to name the ends of logical
#> connections which carry long term conversations.  For the purpose of
#> providing services to unknown callers, a service contact port is
#> defined.  This list specifies the port used by the server process as its
#> contact port.  While the IANA can not control uses of these ports it
#> does register or list uses of these ports as a convienence to the
#> community.
#
socks           1080/tcp                        # socks proxy server
proofd          1093/tcp
rootd           1094/tcp
openvpn         1194/tcp
openvpn         1194/udp
rmiregistry     1099/tcp                        # Java RMI Registry
lotusnote       1352/tcp        lotusnotes      # Lotus Note
ms-sql-s        1433/tcp                        # Microsoft SQL Server
ms-sql-m        1434/udp                        # Microsoft SQL Monitor
ingreslock      1524/tcp
datametrics     1645/tcp        old-radius
datametrics     1645/udp        old-radius
sa-msg-port     1646/tcp        old-radacct
sa-msg-port     1646/udp        old-radacct
kermit          1649/tcp
groupwise       1677/tcp
l2f             1701/udp        l2tp
radius          1812/tcp
radius          1812/udp
radius-acct     1813/tcp        radacct         # Radius Accounting
radius-acct     1813/udp        radacct
cisco-sccp      2000/tcp                        # Cisco SCCP
nfs             2049/tcp                        # Network File System
nfs             2049/udp                        # Network File System
gnunet          2086/tcp
gnunet          2086/udp
rtcm-sc104      2101/tcp                        # RTCM SC-104 IANA 1/29/99
rtcm-sc104      2101/udp
gsigatekeeper   2119/tcp
gris            2135/tcp                # Grid Resource Information Server
cvspserver      2401/tcp                        # CVS client/server operations
venus           2430/tcp                        # codacon port
venus           2430/udp                        # Venus callback/wbc interface
venus-se        2431/tcp                        # tcp side effects
venus-se        2431/udp                        # udp sftp side effect
codasrv         2432/tcp                        # not used
codasrv         2432/udp                        # server port
codasrv-se      2433/tcp                        # tcp side effects
codasrv-se      2433/udp                        # udp sftp side effect
mon             2583/tcp                        # MON traps
mon             2583/udp
dict            2628/tcp                        # Dictionary server
f5-globalsite   2792/tcp
gsiftp          2811/tcp
gpsd            2947/tcp
gds-db          3050/tcp        gds_db          # InterBase server
icpv2           3130/udp        icp             # Internet Cache Protocol
isns            3205/tcp                        # iSNS Server Port
isns            3205/udp                        # iSNS Server Port
iscsi-target    3260/tcp
mysql           3306/tcp
ms-wbt-server   3389/tcp
nut             3493/tcp                        # Network UPS Tools
nut             3493/udp
distcc          3632/tcp                        # distributed compiler
daap            3689/tcp                        # Digital Audio Access Protocol
svn             3690/tcp        subversion      # Subversion protocol
suucp           4031/tcp                        # UUCP over SSL
sysrqd          4094/tcp                        # sysrq daemon
sieve           4190/tcp                        # ManageSieve Protocol
epmd            4369/tcp                        # Erlang Port Mapper Daemon
remctl          4373/tcp                # Remote Authenticated Command Service
f5-iquery       4353/tcp                        # F5 iQuery
ntske           4460/tcp        # Network Time Security Key Establishment
ipsec-nat-t     4500/udp                        # IPsec NAT-Traversal [RFC3947]
iax             4569/udp                        # Inter-Asterisk eXchange
mtn             4691/tcp                        # monotone Netsync Protocol
radmin-port     4899/tcp                        # RAdmin Port
sip             5060/tcp                        # Session Initiation Protocol
sip             5060/udp
sip-tls         5061/tcp
sip-tls         5061/udp
xmpp-client     5222/tcp        jabber-client   # Jabber Client Connection
xmpp-server     5269/tcp        jabber-server   # Jabber Server Connection
cfengine        5308/tcp
mdns            5353/udp                        # Multicast DNS
postgresql      5432/tcp        postgres        # PostgreSQL Database
freeciv         5556/tcp        rptp            # Freeciv gameplay
amqps           5671/tcp                        # AMQP protocol over TLS/SSL
amqp            5672/tcp
amqp            5672/sctp
coap            5683/tcp                # Constrained Application Protocol
coap            5683/udp                # Constrained Application Protocol
coaps           5684/tcp                        # TLS-secured CoAP
coaps           5684/udp                        # DTLS-secured CoAP
x11             6000/tcp        x11-0           # X Window System
x11-1           6001/tcp
x11-2           6002/tcp
x11-3           6003/tcp
x11-4           6004/tcp
x11-5           6005/tcp
x11-6           6006/tcp
x11-7           6007/tcp
gnutella-svc    6346/tcp                        # gnutella
gnutella-svc    6346/udp
gnutella-rtr    6347/tcp                        # gnutella
gnutella-rtr    6347/udp
redis           6379/tcp
sge-qmaster     6444/tcp        sge_qmaster     # Grid Engine Qmaster Service
sge-execd       6445/tcp        sge_execd       # Grid Engine Execution Service
mysql-proxy     6446/tcp                        # MySQL Proxy
babel           6696/udp                        # Babel Routing Protocol
ircs-u          6697/tcp                # Internet Relay Chat via TLS/SSL
bbs             7000/tcp
afs3-fileserver 7000/udp
afs3-callback   7001/udp                        # callbacks to cache managers
afs3-prserver   7002/udp                        # users & groups database
afs3-vlserver   7003/udp                        # volume location database
afs3-kaserver   7004/udp                        # AFS/Kerberos authentication
afs3-volser     7005/udp                        # volume managment server
afs3-bos        7007/udp                        # basic overseer process
afs3-update     7008/udp                        # server-to-server updater
afs3-rmtsys     7009/udp                        # remote cache manager service
font-service    7100/tcp        xfs             # X Font Service
http-alt        8080/tcp        webcache        # WWW caching service
puppet          8140/tcp                        # The Puppet master service
bacula-dir      9101/tcp                        # Bacula Director
bacula-fd       9102/tcp                        # Bacula File Daemon
bacula-sd       9103/tcp                        # Bacula Storage Daemon
xmms2           9667/tcp        # Cross-platform Music Multiplexing System
nbd             10809/tcp                       # Linux Network Block Device
zabbix-agent    10050/tcp                       # Zabbix Agent
zabbix-trapper  10051/tcp                       # Zabbix Trapper
amanda          10080/tcp                       # amanda backup services
dicom           11112/tcp
hkp             11371/tcp                       # OpenPGP HTTP Keyserver
db-lsp          17500/tcp                       # Dropbox LanSync Protocol
dcap            22125/tcp                       # dCache Access Protocol
gsidcap         22128/tcp                       # GSI dCache Access Protocol
wnn6            22273/tcp                       # wnn6

#
# Datagram Delivery Protocol services
#
rtmp            1/ddp                   # Routing Table Maintenance Protocol
nbp             2/ddp                   # Name Binding Protocol
echo            4/ddp                   # AppleTalk Echo Protocol
zip             6/ddp                   # Zone Information Protocol

#=========================================================================
# The remaining port numbers are not as allocated by IANA.
#=========================================================================

# Kerberos (Project Athena/MIT) services
kerberos4       750/udp         kerberos-iv kdc # Kerberos (server)
kerberos4       750/tcp         kerberos-iv kdc
kerberos-master 751/udp         kerberos_master # Kerberos authentication
kerberos-master 751/tcp
passwd-server   752/udp         passwd_server   # Kerberos passwd server
krb-prop        754/tcp         krb_prop krb5_prop hprop # Kerberos slave propagation
zephyr-srv      2102/udp                        # Zephyr server
zephyr-clt      2103/udp                        # Zephyr serv-hm connection
zephyr-hm       2104/udp                        # Zephyr hostmanager
iprop           2121/tcp                        # incremental propagation
supfilesrv      871/tcp                 # Software Upgrade Protocol server
supfiledbg      1127/tcp                # Software Upgrade Protocol debugging

#
# Services added for the Debian GNU/Linux distribution
#
poppassd        106/tcp                         # Eudora
moira-db        775/tcp         moira_db        # Moira database
moira-update    777/tcp         moira_update    # Moira update protocol
moira-ureg      779/udp         moira_ureg      # Moira user registration
spamd           783/tcp                         # spamassassin daemon
skkserv         1178/tcp                        # skk jisho server port
predict         1210/udp                        # predict -- satellite tracking
rmtcfg          1236/tcp                        # Gracilis Packeten remote config server
xtel            1313/tcp                        # french minitel
xtelw           1314/tcp                        # french minitel
zebrasrv        2600/tcp                        # zebra service
zebra           2601/tcp                        # zebra vty
ripd            2602/tcp                        # ripd vty (zebra)
ripngd          2603/tcp                        # ripngd vty (zebra)
ospfd           2604/tcp                        # ospfd vty (zebra)
bgpd            2605/tcp                        # bgpd vty (zebra)
ospf6d          2606/tcp                        # ospf6d vty (zebra)
ospfapi         2607/tcp                        # OSPF-API
isisd           2608/tcp                        # ISISd vty (zebra)
fax             4557/tcp                        # FAX transmission service (old)
hylafax         4559/tcp                        # HylaFAX client-server protocol (new)
munin           4949/tcp        lrrd            # Munin
rplay           5555/udp                        # RPlay audio service
nrpe            5666/tcp                        # Nagios Remote Plugin Executor
nsca            5667/tcp                        # Nagios Agent - NSCA
canna           5680/tcp                        # cannaserver
syslog-tls      6514/tcp                        # Syslog over TLS [RFC5425]
sane-port       6566/tcp        sane saned      # SANE network scanner daemon
ircd            6667/tcp                        # Internet Relay Chat
zope-ftp        8021/tcp                        # zope management by ftp
tproxy          8081/tcp                        # Transparent Proxy
omniorb         8088/tcp                        # OmniORB
clc-build-daemon 8990/tcp                       # Common lisp build daemon
xinetd          9098/tcp
git             9418/tcp                        # Git Version Control System
zope            9673/tcp                        # zope server
webmin          10000/tcp
kamanda         10081/tcp                       # amanda backup services (Kerberos)
amandaidx       10082/tcp                       # amanda backup services
amidxtape       10083/tcp                       # amanda backup services
sgi-cmsd        17001/udp               # Cluster membership services daemon
sgi-crsd        17002/udp
sgi-gcd         17003/udp                       # SGI Group membership daemon
sgi-cad         17004/tcp                       # Cluster Admin daemon
binkp           24554/tcp                       # binkp fidonet protocol
asp             27374/tcp                       # Address Search Protocol
asp             27374/udp
csync2          30865/tcp                       # cluster synchronization tool
dircproxy       57000/tcp                       # Detachable IRC Proxy
tfido           60177/tcp                       # fidonet EMSI over telnet
fido            60179/tcp                       # fidonet EMSI over TCP

# Local services
```

`/etc/services`에서 서비스 이름과 포트 번호, 프로토콜 정보를 확인했다.

---

### 실습 8. /etc/services의 내용을 페이지 단위로 출력한다

#### 실행한 명령어

```console
$ more /etc/services
```

#### 실행 결과

```text
# Network services, Internet style
#
# Updated from https://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.xhtml .
#
# New ports will be added on request if they have been officially assigned
# by IANA and used in the real-world or are needed by a debian package.
# If you need a huge list of used numbers please install the nmap package.

tcpmux          1/tcp                           # TCP port service multiplexer
echo            7/tcp
echo            7/udp
discard         9/tcp           sink null
discard         9/udp           sink null
systat          11/tcp          users
daytime         13/tcp
daytime         13/udp
netstat         15/tcp
qotd            17/tcp          quote
chargen         19/tcp          ttytst source
chargen         19/udp          ttytst source
ftp-data        20/tcp
ftp             21/tcp
fsp             21/udp          fspd
ssh             22/tcp                          # SSH Remote Login Protocol
telnet          23/tcp
smtp            25/tcp          mail
time            37/tcp          timserver
--More--(6%)
```

`more`는 긴 파일을 화면 단위로 나누어 출력하며, `--More--`는 현재 읽은 진행률을 표시한다.

---

### 실습 9. /etc/services의 내용을 페이지 단위로 출력한다

#### 실행한 명령어와 결과
```console
$ head /etc/services
# Network services, Internet style
#
# Updated from https://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.xhtml .
#
# New ports will be added on request if they have been officially assigned
# by IANA and used in the real-world or are needed by a debian package.
# If you need a huge list of used numbers please install the nmap package.

tcpmux          1/tcp                           # TCP port service multiplexer
```

```console
$ tail /etc/services
sgi-cad         17004/tcp                       # Cluster Admin daemon
binkp           24554/tcp                       # binkp fidonet protocol
asp             27374/tcp                       # Address Search Protocol
asp             27374/udp
csync2          30865/tcp                       # cluster synchronization tool
dircproxy       57000/tcp                       # Detachable IRC Proxy
tfido           60177/tcp                       # fidonet EMSI over telnet
fido            60179/tcp                       # fidonet EMSI over TCP
```

`head`는 파일의 앞부분을, `tail`은 파일의 뒷부분을 기본 10줄씩 출력한다.

---

### 실습 10. /etc/services의 단어를 세서 출력한다

#### 실행한 명령어와 결과

```console
$ wc /etc/services
 365  1795 12990 /etc/services
```

`wc`의 출력은 줄 수, 단어 수, 바이트 수, 파일 이름 순서이다.

---

### 실습 11. 종합 실습

#### 실행한 명령어와 결과

```console
$ cd ~/linux/ch03
$ mkdir practice
$ touch a.txt b.txt
$ ls -la
total 16
drwxr-xr-x 3 user user 4096 Sep 16 17:12 .
drwxr-xr-x 3 user user 4096 Sep 16 17:05 ..
-rw-r--r-- 1 user user    0 Sep 16 17:12 a.txt
-rw-r--r-- 1 user user    0 Sep 16 17:12 b.txt
drwxr-xr-x 2 user user 4096 Sep 16 17:12 practice
-rw-r--r-- 1 user user   29 Sep 16 17:05 test.txt
$ vi a.txt
$ cat a.txt
1번째 줄
2번째 줄
3번째 줄
$ head a.txt
1번째 줄
2번째 줄
3번째 줄
$ tail a.txt
1번째 줄
2번째 줄
3번째 줄
$ wc a.txt
 3  6 36 a.txt
$ cd /mnt/c
$ ls
 '$RECYCLE.BIN'             Setup.log                     bootTel.dat
 Config.Msi                 'System Volume Information'   hiberfil.sys
 'Documents and Settings'   TCGameApps                    inetpub
 DumpStack.log              Temp                          mingw64
 DumpStack.log.tmp          User_guide                    pagefile.sys
 PerfLogs                   Users                         recovery
 'Program Files'            Wallpaper                     swapfile.sys
 'Program Files (x86)'      Windows                       ''$'\353\260\260\352\262\275\355\231\224\353\251\264''.jpg'
 ProgramData                XboxGames                     ''$'\354\236\240\352\270\210\355\231\224\353\251\264''.jpg'
 'Riot Games'               adobeTemp                     ''$'\354\244\221\352\265\255\354\271\264\355\212\270'
$ pwd
 /mnt/c
```

`~/linux/ch03`에서 `practice` 디렉터리와 `a.txt`, `b.txt`를 만들고, `vi`로 `a.txt`에 세 줄을 입력했다. 이후 `cat`, `head`, `tail`, `wc`로 파일 내용을 확인하고, `/mnt/c`에서 Windows C: 드라이브의 내용과 현재 경로를 확인했다.

---

### 실습 12. vi 에디터를 이용한 C 프로그램 작성 및 편집

#### 실행한 명령어와 결과

```console
$ vi test.c
$ cat test.c
#include <stdio.h>

int main() {
        printf("This is vi editor\n");
        printf("Hello Ubuntu\n");
        printf("Learing Ubuntu is fun\n");
        printf("Ubuntu is powerful\n");
        printf("welcome to Ubuntu\n");
        return 0;
}
```

`vi`에서 `i`와 `o`로 내용을 입력하고, `h`, `j`, `k`, `l`로 커서를 이동했다. `dd`로 줄을 삭제한 뒤 `u`로 취소하고, `yy`와 `P`로 복사·붙여넣기, `/Linux`와 `n`으로 문자열 검색, `:%s/Linux/Ubuntu/g`로 문자열 일괄 변경을 실습했다. 마지막으로 `Esc`를 누른 후 `:wq`로 저장하고 종료했다.

---
