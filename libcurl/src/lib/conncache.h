#ifndef HEADER_CURL_CONNCACHE_H
#define HEADER_CURL_CONNCACHE_H
/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 2015, Daniel Stenberg, <daniel@haxx.se>, et al.
 * Copyright (C) 2012 - 2014, Linus Nielsen Feltzing, <linus@haxx.se>
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

struct conncache {
  struct curl_hash *hash;
  size_t num_connections;
  long next_connection_id;
  struct timeval last_cleanup;
};

CURL_STATIC struct conncache *Curl_conncache_init(int size);

CURL_STATIC void Curl_conncache_destroy(struct conncache *connc);

/* return the correct bundle, to a host or a proxy */
CURL_STATIC struct connectbundle *Curl_conncache_find_bundle(struct connectdata *conn,
                                                 struct conncache *connc);

CURL_STATIC CURLcode Curl_conncache_add_conn(struct conncache *connc,
                                 struct connectdata *conn);

CURL_STATIC void Curl_conncache_remove_conn(struct conncache *connc,
                                struct connectdata *conn);

CURL_STATIC void Curl_conncache_foreach(struct conncache *connc,
                            void *param,
                            int (*func)(struct connectdata *conn,
                                        void *param));

CURL_STATIC struct connectdata *
Curl_conncache_find_first_connection(struct conncache *connc);

CURL_STATIC void Curl_conncache_print(struct conncache *connc);

#endif /* HEADER_CURL_CONNCACHE_H */
