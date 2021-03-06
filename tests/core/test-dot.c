/* Copyright 2014 Nodalink EURL
 *
 * This file is part of Packetgraph.
 *
 * Packetgraph is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as published
 * by the Free Software Foundation.
 *
 * Packetgraph is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Packetgraph.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <glib.h>
#include <string.h>

#include <packetgraph/packetgraph.h>
#include "utils/tests.h"
#include "tests.h"

#define RESULT_SIZE 100000

static void test_brick_core_dot(void)
{
	/* Create a weird graph and make a representation using dot.
	 *
	 *   [A]--------------------[B]--------------------[C]
	 *       \                                         |
	 *         --------------                          |
	 *                        \                        |
	 *   [D]--------------------[E]------------------[F]
	 *   |
	 *   |
	 *   |
	 * [G]--------------------[H]--------------------[I]
	 *                        |
	 *                        |
	 *                      [J]----------------------[K]
	 *
	 */
	int ret;
	struct pg_brick *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k;
	struct pg_error *error = NULL;
	char result[RESULT_SIZE];
	FILE *fd;

	a = pg_hub_new("a", 5, 5, &error);
	g_assert(!error);
	b = pg_hub_new("b", 5, 5, &error);
	g_assert(!error);
	c = pg_hub_new("c", 5, 5, &error);
	g_assert(!error);
	d = pg_hub_new("d", 5, 5, &error);
	g_assert(!error);
	e = pg_hub_new("e", 5, 5, &error);
	g_assert(!error);
	f = pg_hub_new("f", 5, 5, &error);
	g_assert(!error);
	g = pg_hub_new("g", 5, 5, &error);
	g_assert(!error);
	h = pg_hub_new("h", 5, 5, &error);
	g_assert(!error);
	i = pg_hub_new("i", 5, 5, &error);
	g_assert(!error);
	j = pg_hub_new("j", 5, 5, &error);
	g_assert(!error);
	k = pg_hub_new("k", 5, 5, &error);
	g_assert(!error);

	pg_brick_chained_links(&error, a, b, c);
	g_assert(!error);
	pg_brick_chained_links(&error, g, d, e, f, c);
	g_assert(!error);
	pg_brick_chained_links(&error, a, e);
	g_assert(!error);
	pg_brick_chained_links(&error, g, h, i);
	g_assert(!error);
	pg_brick_chained_links(&error, j, k);
	g_assert(!error);
	pg_brick_chained_links(&error, j, h);
	g_assert(!error);

	fd = fmemopen(result, RESULT_SIZE, "w+");
	ret = pg_brick_dot(k, fd, &error);
	fclose(fd);
	g_assert(!error);
	g_assert(ret == 0);

	/* ugly test is ugly */

	/* unsigned int x; */
	/* printf("\n{"); */
	/* 	for (x = 0; x < strlen(result); x++) */
	/* 		printf("%i,", result[x]); */
	/* printf("};\n"); */

	char compare[] =
		{115,116,114,105,99,116,32,103,114,97,112,104,32,71,32,123,10,32,32,114,97,110,107,100,105,114,61,76,82,10,32,32,110,111,100,101,115,101,112,61,49,10,32,32,110,111,100,101,32,91,115,104,97,112,101,61,114,101,99,111,114,100,93,59,10,32,32,34,104,117,98,58,107,34,32,91,32,108,97,98,101,108,61,34,123,32,60,119,101,115,116,62,32,124,32,104,117,98,38,35,57,50,59,110,107,32,124,60,101,97,115,116,62,32,125,34,93,59,10,32,32,34,104,117,98,58,107,34,58,119,101,115,116,32,45,45,32,34,104,117,98,58,106,34,58,101,97,115,116,10,32,32,34,104,117,98,58,106,34,32,91,32,108,97,98,101,108,61,34,123,32,60,119,101,115,116,62,32,124,32,104,117,98,38,35,57,50,59,110,106,32,124,60,101,97,115,116,62,32,125,34,93,59,10,32,32,34,104,117,98,58,106,34,58,101,97,115,116,32,45,45,32,34,104,117,98,58,107,34,58,119,101,115,116,10,32,32,34,104,117,98,58,106,34,58,101,97,115,116,32,45,45,32,34,104,117,98,58,104,34,58,119,101,115,116,10,32,32,34,104,117,98,58,104,34,32,91,32,108,97,98,101,108,61,34,123,32,60,119,101,115,116,62,32,124,32,104,117,98,38,35,57,50,59,110,104,32,124,60,101,97,115,116,62,32,125,34,93,59,10,32,32,34,104,117,98,58,104,34,58,119,101,115,116,32,45,45,32,34,104,117,98,58,103,34,58,101,97,115,116,10,32,32,34,104,117,98,58,104,34,58,119,101,115,116,32,45,45,32,34,104,117,98,58,106,34,58,101,97,115,116,10,32,32,34,104,117,98,58,104,34,58,101,97,115,116,32,45,45,32,34,104,117,98,58,105,34,58,119,101,115,116,10,32,32,34,104,117,98,58,103,34,32,91,32,108,97,98,101,108,61,34,123,32,60,119,101,115,116,62,32,124,32,104,117,98,38,35,57,50,59,110,103,32,124,60,101,97,115,116,62,32,125,34,93,59,10,32,32,34,104,117,98,58,103,34,58,101,97,115,116,32,45,45,32,34,104,117,98,58,100,34,58,119,101,115,116,10,32,32,34,104,117,98,58,103,34,58,101,97,115,116,32,45,45,32,34,104,117,98,58,104,34,58,119,101,115,116,10,32,32,34,104,117,98,58,105,34,32,91,32,108,97,98,101,108,61,34,123,32,60,119,101,115,116,62,32,124,32,104,117,98,38,35,57,50,59,110,105,32,124,60,101,97,115,116,62,32,125,34,93,59,10,32,32,34,104,117,98,58,105,34,58,119,101,115,116,32,45,45,32,34,104,117,98,58,104,34,58,101,97,115,116,10,32,32,34,104,117,98,58,100,34,32,91,32,108,97,98,101,108,61,34,123,32,60,119,101,115,116,62,32,124,32,104,117,98,38,35,57,50,59,110,100,32,124,60,101,97,115,116,62,32,125,34,93,59,10,32,32,34,104,117,98,58,100,34,58,119,101,115,116,32,45,45,32,34,104,117,98,58,103,34,58,101,97,115,116,10,32,32,34,104,117,98,58,100,34,58,101,97,115,116,32,45,45,32,34,104,117,98,58,101,34,58,119,101,115,116,10,32,32,34,104,117,98,58,101,34,32,91,32,108,97,98,101,108,61,34,123,32,60,119,101,115,116,62,32,124,32,104,117,98,38,35,57,50,59,110,101,32,124,60,101,97,115,116,62,32,125,34,93,59,10,32,32,34,104,117,98,58,101,34,58,119,101,115,116,32,45,45,32,34,104,117,98,58,100,34,58,101,97,115,116,10,32,32,34,104,117,98,58,101,34,58,119,101,115,116,32,45,45,32,34,104,117,98,58,97,34,58,101,97,115,116,10,32,32,34,104,117,98,58,101,34,58,101,97,115,116,32,45,45,32,34,104,117,98,58,102,34,58,119,101,115,116,10,32,32,34,104,117,98,58,97,34,32,91,32,108,97,98,101,108,61,34,123,32,60,119,101,115,116,62,32,124,32,104,117,98,38,35,57,50,59,110,97,32,124,60,101,97,115,116,62,32,125,34,93,59,10,32,32,34,104,117,98,58,97,34,58,101,97,115,116,32,45,45,32,34,104,117,98,58,98,34,58,119,101,115,116,10,32,32,34,104,117,98,58,97,34,58,101,97,115,116,32,45,45,32,34,104,117,98,58,101,34,58,119,101,115,116,10,32,32,34,104,117,98,58,102,34,32,91,32,108,97,98,101,108,61,34,123,32,60,119,101,115,116,62,32,124,32,104,117,98,38,35,57,50,59,110,102,32,124,60,101,97,115,116,62,32,125,34,93,59,10,32,32,34,104,117,98,58,102,34,58,119,101,115,116,32,45,45,32,34,104,117,98,58,101,34,58,101,97,115,116,10,32,32,34,104,117,98,58,102,34,58,101,97,115,116,32,45,45,32,34,104,117,98,58,99,34,58,119,101,115,116,10,32,32,34,104,117,98,58,98,34,32,91,32,108,97,98,101,108,61,34,123,32,60,119,101,115,116,62,32,124,32,104,117,98,38,35,57,50,59,110,98,32,124,60,101,97,115,116,62,32,125,34,93,59,10,32,32,34,104,117,98,58,98,34,58,119,101,115,116,32,45,45,32,34,104,117,98,58,97,34,58,101,97,115,116,10,32,32,34,104,117,98,58,98,34,58,101,97,115,116,32,45,45,32,34,104,117,98,58,99,34,58,119,101,115,116,10,32,32,34,104,117,98,58,99,34,32,91,32,108,97,98,101,108,61,34,123,32,60,119,101,115,116,62,32,124,32,104,117,98,38,35,57,50,59,110,99,32,124,60,101,97,115,116,62,32,125,34,93,59,10,32,32,34,104,117,98,58,99,34,58,119,101,115,116,32,45,45,32,34,104,117,98,58,98,34,58,101,97,115,116,10,32,32,34,104,117,98,58,99,34,58,119,101,115,116,32,45,45,32,34,104,117,98,58,102,34,58,101,97,115,116,10,125,10,0};

	g_assert(memcmp(compare, result, strlen(compare)) == 0);

	pg_brick_destroy(a);
	pg_brick_destroy(b);
	pg_brick_destroy(c);
	pg_brick_destroy(d);
	pg_brick_destroy(e);
	pg_brick_destroy(f);
	pg_brick_destroy(g);
	pg_brick_destroy(h);
	pg_brick_destroy(i);
	pg_brick_destroy(j);
	pg_brick_destroy(k);
}

void test_brick_dot(void)
{
	pg_test_add_func("/core/dot", test_brick_core_dot);
}
