# ifndef CURL_STATICLIB
# define CURL_STATICLIB
# endif

# define BUILDING_LIBCURL
# if !defined(CURL_STATICLIB)
#     define CURL_STATICLIB
# endif

// #include "InternalOverrides.h"

# if defined(WINAPI_FAMILY)
#     include <winapifamily.h>
#     if WINAPI_FAMILY_PARTITION(WINAPI_FAMILY_APP) || WINAPI_FAMILY_PARTITION(WINAPI_FAMILY_PHONE_APP)
#         define CURL_WINRT
#     endif
# endif

# if !defined(CURL_DISABLE_TYPECHECK)
#     define CURL_DISABLE_TYPECHECK
# endif
# define CURL_DISABLE_CRYPTO_AUTH
# define CURL_DISABLE_TFTP
# define CURL_DISABLE_FTP
# define CURL_DISABLE_LDAP
# define CURL_DISABLE_TELNET
# define CURL_DISABLE_DICT
# define CURL_DISABLE_FILE
# define CURL_DISABLE_RTSP
# define CURL_DISABLE_POP3
# define CURL_DISABLE_IMAP
# define CURL_DISABLE_SMB
# define CURL_DISABLE_SMTP
# define CURL_DISABLE_RTMP
# define CURL_DISABLE_GOPHER

# define CURL_STATIC                static __inline
# define CURL_STATIC_VAR            static 
# define CURL_STATIC_DEF(t,n,v)
# define CURL_STATIC_DECL(t,n,v)    static t n = v

//# define USE_AXTLS
# define USE_SCHANNEL
# define USE_WINDOWS_SSPI // USE_SCHANNEL require this

# include "lib/mprintf.c"

# include "lib/urldata.h"

static const struct Curl_handler Curl_handler_http;
# if defined(USE_SSL)
static const struct Curl_handler Curl_handler_https;
# endif

//# include "lib/vtls/axtls.c"
//# include "lib/vtls/darwinssl.c"
# include "lib/vtls/schannel.c"
//# include "lib/vtls/cyassl.c"
//# include "lib/vtls/gskit.c"
//# include "lib/vtls/gtls.c"
//# include "lib/vtls/nss.c"
//# include "lib/vtls/openssl.c"
//# include "lib/vtls/polarssl.c"
//# include "lib/vtls/polarssl_threadlock.c"
# include "lib/vtls/vtls.c"
//# include "lib/amigaos.c"
//# include "lib/asyn-ares.c"
# include "lib/asyn-thread.c"
# include "lib/base64.c"
# include "lib/bundles.c"
# include "lib/conncache.c"
# include "lib/connect.c"
//# include "lib/content_encoding.c"
# include "lib/cookie.c"
# include "lib/parsedate.c" // earlier so Curl_wkday and Curl_month will be defined
//# include "lib/dict.c"
# include "lib/dotdot.c"
# include "lib/easy.c"
# include "lib/escape.c"
//# include "lib/file.c"
# include "lib/fileinfo.c"
# include "lib/formdata.c"
//# include "lib/ftp.c"
//# include "lib/ftplistparser.c"
# include "lib/getenv.c"
# include "lib/getinfo.c"
//# include "lib/gopher.c"
# include "lib/hash.c"
//# include "lib/hmac.c"
# include "lib/hostasyn.c"
//# include "lib/hostcheck.c"
# include "lib/hostip.c"
# include "lib/hostip4.c"
//# include "lib/hostip6.c"
//# include "lib/hostsyn.c"
# include "lib/http.c"
# include "lib/http_chunks.c"
//# include "lib/http_digest.c"
//# include "lib/http_negotiate.c"
//# include "lib/http_negotiate_sspi.c"
# include "lib/http_proxy.c"
//# include "lib/http2.c"
//# include "lib/idn_win32.c"
# include "lib/if2ip.c"
//# include "lib/imap.c"
# include "lib/inet_ntop.c"
# include "lib/inet_pton.c"
//# include "lib/krb5.c"
//# include "lib/ldap.c"
# include "lib/llist.c"
//# include "lib/md4.c"
//# include "lib/md5.c"
//# include "lib/memdebug.c"
# include "lib/multi.c"
# include "lib/netrc.c"
//# include "lib/non-ascii.c"
# include "lib/nonblock.c"
//# include "lib/nwlib.c"
//# include "lib/nwos.c"
//# include "lib/openldap.c"
//# include "lib/pingpong.c"
# include "lib/pipeline.c"
//# include "lib/pop3.c"
# include "lib/progress.c"
# include "lib/rawstr.c"
//# include "lib/rtsp.c"
//# include "lib/security.c"
# include "lib/select.c"
# include "lib/sendf.c"
# include "lib/share.c"
# include "lib/slist.c"
//# include "lib/smb.c"
//# include "lib/smtp.c"
# include "lib/socks.c"
//# include "lib/socks_gssapi.c"
# include "lib/socks_sspi.c"
# include "lib/speedcheck.c"
# include "lib/splay.c"
//# include "lib/ssh.c"
# include "lib/strdup.c"
# include "lib/strequal.c"
# include "lib/strerror.c"
# include "lib/strtok.c"
//# include "lib/strtoofft.c"
//# include "lib/telnet.c"
//# include "lib/tftp.c"
# include "lib/timeval.c"
# include "lib/transfer.c"
# include "lib/url.c"
//# include "lib/version.c"
# include "lib/warnless.c"
# include "lib/wildcard.c"
//# include "lib/x509asn1.c"

# include "lib/curl_addrinfo.c"
//# include "lib/curl_des.c"
//# include "lib/curl_endian.c"
//# include "lib/curl_fnmatch.c"
//# include "lib/curl_gethostname.c"
//# include "lib/curl_gssapi.c"
# include "lib/curl_memrchr.c"
# include "lib/curl_multibyte.c"
//# include "lib/curl_ntlm.c"
//# include "lib/curl_ntlm_core.c"
//# include "lib/curl_ntlm_msgs.c"
//# include "lib/curl_ntlm_wb.c"
//# include "lib/curl_rtmp.c"
//# include "lib/curl_sasl.c"
//# include "lib/curl_sasl_sspi.c"
//# include "lib/curl_sasl_gssapi.c"
# include "lib/curl_sspi.c"
# include "lib/curl_threads.c"
