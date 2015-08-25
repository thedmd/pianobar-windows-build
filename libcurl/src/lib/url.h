#ifndef HEADER_CURL_URL_H
#define HEADER_CURL_URL_H
/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2013, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at http://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
#include "curl_setup.h"

/*
 * Prototypes for library-wide functions provided by url.c
 */

CURL_STATIC CURLcode Curl_open(struct SessionHandle **curl);
CURL_STATIC CURLcode Curl_init_userdefined(struct UserDefined *set);
CURL_STATIC CURLcode Curl_setopt(struct SessionHandle *data, CURLoption option,
                     va_list arg);
CURL_STATIC CURLcode Curl_dupset(struct SessionHandle * dst, struct SessionHandle * src);
CURL_STATIC void Curl_freeset(struct SessionHandle * data);
CURL_STATIC CURLcode Curl_close(struct SessionHandle *data); /* opposite of curl_open() */
CURL_STATIC CURLcode Curl_connect(struct SessionHandle *, struct connectdata **,
                      bool *async, bool *protocol_connect);
CURL_STATIC CURLcode Curl_do(struct connectdata **, bool *done);
CURL_STATIC CURLcode Curl_do_more(struct connectdata *, int *completed);
CURL_STATIC CURLcode Curl_done(struct connectdata **, CURLcode, bool premature);
CURL_STATIC CURLcode Curl_disconnect(struct connectdata *, bool dead_connection);
CURL_STATIC CURLcode Curl_protocol_connect(struct connectdata *conn, bool *done);
CURL_STATIC CURLcode Curl_protocol_connecting(struct connectdata *conn, bool *done);
CURL_STATIC CURLcode Curl_protocol_doing(struct connectdata *conn, bool *done);
CURL_STATIC CURLcode Curl_setup_conn(struct connectdata *conn,
                         bool *protocol_done);
CURL_STATIC void Curl_free_request_state(struct SessionHandle *data);

CURL_STATIC int Curl_protocol_getsock(struct connectdata *conn,
                          curl_socket_t *socks,
                          int numsocks);
CURL_STATIC int Curl_doing_getsock(struct connectdata *conn,
                       curl_socket_t *socks,
                       int numsocks);

CURL_STATIC bool Curl_isPipeliningEnabled(const struct SessionHandle *handle);
CURL_STATIC CURLcode Curl_addHandleToPipeline(struct SessionHandle *handle,
                                  struct curl_llist *pipeline);
CURL_STATIC int Curl_removeHandleFromPipeline(struct SessionHandle *handle,
                                  struct curl_llist *pipeline);
/* remove the specified connection from all (possible) pipelines and related
   queues */
CURL_STATIC void Curl_getoff_all_pipelines(struct SessionHandle *data,
                               struct connectdata *conn);

CURL_STATIC void Curl_close_connections(struct SessionHandle *data);

#define CURL_DEFAULT_PROXY_PORT 1080 /* default proxy port unless specified */
#define CURL_DEFAULT_SOCKS5_GSSAPI_SERVICE "rcmd" /* default socks5 gssapi
                                                     service */

CURL_STATIC CURLcode Curl_connected_proxy(struct connectdata *conn, int sockindex);

#ifdef CURL_DISABLE_VERBOSE_STRINGS
#define Curl_verboseconnect(x)  Curl_nop_stmt
#else
CURL_STATIC void Curl_verboseconnect(struct connectdata *conn);
#endif


#endif /* HEADER_CURL_URL_H */
