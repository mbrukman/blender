/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "BLI_listbase.h"
#include "node_simulation_util.h"

static bNodeSocketTemplate sim_node_particle_attribute_in[] = {
    {SOCK_STRING, N_("Name")},
    {-1, ""},
};

static bNodeSocketTemplate sim_node_particle_attribute_out[] = {
    {SOCK_FLOAT, N_("Float")},
    {SOCK_INT, N_("Int")},
    {SOCK_BOOLEAN, N_("Boolean")},
    {SOCK_VECTOR, N_("Vector")},
    {SOCK_RGBA, N_("Color")},
    {SOCK_OBJECT, N_("Object")},
    {SOCK_IMAGE, N_("Image")},
    {-1, ""},
};

static void sim_node_particle_attribute_update(bNodeTree *UNUSED(ntree), bNode *node)
{
  LISTBASE_FOREACH (bNodeSocket *, sock, &node->outputs) {
    nodeSetSocketAvailability(sock, sock->type == node->custom1);
  }
}

void register_node_type_sim_particle_attribute()
{
  static bNodeType ntype;

  sim_node_type_base(&ntype, SIM_NODE_PARTICLE_ATTRIBUTE, "Particle Attribute", 0, 0);
  node_type_socket_templates(
      &ntype, sim_node_particle_attribute_in, sim_node_particle_attribute_out);
  node_type_update(&ntype, sim_node_particle_attribute_update);
  nodeRegisterType(&ntype);
}
