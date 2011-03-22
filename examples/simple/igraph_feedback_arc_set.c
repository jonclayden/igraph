/* -*- mode: C -*-  */
/* vim:set ts=2 sw=2 sts=2 et: */
/* 
   IGraph library.
   Copyright (C) 2011  Gabor Csardi <csardi@rmki.kfki.hu>
   MTA RMKI, Konkoly-Thege Miklos st. 29-33, Budapest 1121, Hungary
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA 
   02110-1301 USA

*/

#include <igraph.h>
#include <string.h>

int main() {
  igraph_t g;
  igraph_vector_t weights, result;
  igraph_bool_t dag;

  igraph_vector_init(&result, 0);

  igraph_small(&g, 0, IGRAPH_DIRECTED, 0,1, 1,2, 2,0, 2,3, 2,4, 0,4, 4,3, 5,0, 6,5, -1);
  igraph_feedback_arc_set(&g, &result, 0, IGRAPH_FAS_APPROX_EADES);
  igraph_vector_print(&result);
  igraph_delete_edges(&g, igraph_ess_vector(&result));
  igraph_is_dag(&g, &dag);
  if (!dag)
    return 1;
  igraph_destroy(&g);

  igraph_vector_destroy(&result);

  return 0;
}
