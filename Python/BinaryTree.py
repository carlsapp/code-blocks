#!/usr/bin/env python
# -*- coding: ascii -*-
###############################################################################
# Copyright 2017 Carl Sapp
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
###############################################################################
import random as _random
import Queue as _queue
import sys as _sys
import math as _math


class BinaryTreeNode(object):
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

    def insert_random(self, value=_random.randint(0, 10)):
        # Should we go left or right?
        if _random.randint(0, 1):
            if self.right:
                self.right.insert_random(value=value)
            else:
                self.right = BinaryTreeNode(value)
        else:
            if self.left:
                self.left.insert_random(value=value)
            else:
                self.left = BinaryTreeNode(value)

    def insert_complete(self, value):
        if self.left and self.right:
            # We need to determine if we will insert down the left or right branches
            left_max_depth = self.left.max_depth()
            right_max_depth = self.right.max_depth()
            if left_max_depth > right_max_depth:
                if self.left.is_perfect():
                    # Our left side must have just filled up. Insert on the right.
                    self.right.insert_complete(value)
                else:
                    #print("Inserting on left branch")
                    self.left.insert_complete(value)
            else:
                # Our left and right branches have the same max depth
                if self.right.is_perfect():
                    # If we've been inserting complete the whole time, our tree must be perfect now
                    #print("Inserting on left branch")
                    self.left.insert_complete(value)
                else:
                    self.right.insert_complete(value)
        elif self.left:
            self.right = BinaryTreeNode(value)
        else:
            self.left = BinaryTreeNode(value)

    def is_perfect(self):
        """A tree is not perfect if only one of our branches is filled"""
        if self.left and self.right:
            # Check the max depth
            if self.left.max_depth() != self.right.max_depth():
                return False
            return self.left.is_perfect() and self.right.is_perfect()
        elif self.left is None and self.right is None:
            return True
        else:
            return False

    def max_depth(self):
        """
        Max depth of this node and all children nodes. 0-based. A node that has no children has a max depth of 0.
        :return:
        """
        left_max = right_max = -1
        if self.left:
            left_max = self.left.max_depth()
        if self.right:
            right_max = self.right.max_depth()
        return max(left_max, right_max) + 1

    def max_str_len(self):
        """
        Max depth of this node and all children nodes. 0-based. A node that has no children has a max depth of 0.
        :return:
        """
        left_max = right_max = 0
        if self.left:
            left_max = self.left.max_str_len()
        if self.right:
            right_max = self.right.max_str_len()
        return max(left_max, right_max, len(str(self)))

    def print_tree(self):
        max_depth = self.max_depth()
        max_str_len = self.max_str_len()
        print("Max String Len: %d" % max_str_len)
        node_str_format = "{: ^" + str(max_str_len) + "}"
        # Do a breadth first search, keeping track of the depth and position of the last node printed
        props = {
            # We need to keep track of the last depth printed to know when to print a newline
            'last_depth_printed': -1,
            # We need to keep track of the last position printed to know how many nodes were skipped in a row
            'last_pos_printed': -1,
        }

        def print_node(node, depth, position, props):
            if depth != props['last_depth_printed']:
                if depth > 0:
                    _sys.stdout.write('\n')
                props['last_depth_printed'] = depth
                props['last_pos_printed'] = -1

            node_spacing = 1
            node_char_len = max_str_len
            depth_diff = max_depth - depth
            if depth_diff == 0:
                initial_row_spacing = 0
                spacing_between = node_spacing
            else:
                num_leaves_left = 2**(depth_diff - 1)
                initial_row_spacing = (num_leaves_left - 1) * (node_char_len + node_spacing) + node_char_len - ((node_char_len - 1) / 2)
                num_nodes_between = 2**depth_diff
                spacing_between = (num_nodes_between - 2) * (node_char_len + node_spacing) + node_char_len + (node_spacing * 2)
            positions_skipped = position - props['last_pos_printed'] - 1
            if position == 0 or position - positions_skipped == 0:
                padding_before_len = initial_row_spacing + (positions_skipped * (node_char_len + spacing_between))
            else:
                padding_before_len = (positions_skipped * (node_char_len + node_spacing)) + spacing_between
            padding_before = ' ' * padding_before_len
            node_str = node_str_format.format(node.value)
            _sys.stdout.write(padding_before + node_str)
            props['last_pos_printed'] = position

        self.breadth_first_search(print_node, props)
        _sys.stdout.write('\n')

    def breadth_first_search(self, func, *args, **kwargs):
        bfs_queue = _queue.Queue()
        # Our queue elements will be (node, depth, position)
        bfs_queue.put((self, 0, 0))
        while not bfs_queue.empty():
            node, depth, position = bfs_queue.get()
            func(node, depth, position, *args, **kwargs)
            if node.left:
                bfs_queue.put((node.left, depth + 1, position * 2))
            if node.right:
                bfs_queue.put((node.right, depth + 1, (position * 2) + 1))

    def __str__(self):
        return str(self.value)

    def __repr__(self):
        repr_str = 'BinaryTreeNode({}'.format(self.value)
        if self.left:
            repr_str += ', left=' + repr(self.left)
        if self.right:
            repr_str += ', right=' + repr(self.right)
        return repr_str + ')'


def create_complete_tree(values):
    if len(values) == 0:
        return None
    root = BinaryTreeNode(values[0])
    for value in values[1:]:
        root.insert_complete(value)
    return root


def create_random_tree(values):
    if len(values) == 0:
        return None
    root = BinaryTreeNode(values[0])
    for value in values[1:]:
        root.insert_random(value)
    return root


def print_bfs(node, depth, position):
    print("{} Depth: {} Position: {}".format(node.value, depth, position))


"""

               0                   Depth: 1 Spacing: 15
       0               0           Depth: 2 Spacing: 7/15
   0       0       0       0       Depth: 3 Spacing: 3/7 4 - 1, 8 - 1
 0   0   0   0   0   0   0   0     Depth: 4 Spacing: 1/3 2 - 1, 4 - 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0    Depth: 5 Spacing: 0/1 2**(max_depth - depth)

                                000                   Depth: 1 Spacing: 15
              000                                  000                                Depth: 2 Spacing: 14/
      000             000                 000       000                      Depth: 3 Spacing: 6/13 4 - 1, 8 - 1
  000     000     000     000         000   000   000   000              Depth: 4 Spacing: 2/5 2 - 1, 4 - 1
000 000 000 000 000 000 000 000 000 000 000 000 000 000 000 000    Depth: 5 Spacing: 0/1 2**(max_depth - depth)

       0000
  0000      0000        6
0000 0000 0000 0000

         00000
   00000         00000    7
00000  00000  00000  00000

(node_char_len * 2) + node_spacing - (node_char_len - node_spacing)
= node_char_len + (node_spacing * 2)

depth  max_depth  depth_diff  num_leaves_left  num_nodes_between
1      5          4           8                16
2      5          3           4                8
3      5          2           2                4
4      5          1           1                2
5      5          0           0                0

The number of leaf nodes to the left of the first branch is math.floor(2**(depth_diff - 1)). Called num_leaves_left.
The initial row spacing is (num_leaves_left - 1) * (node_char_len + node_spacing) + math.floor(node_char_len / 2)
if depth_diff == 0:
    initial_row_spacing = 0
    spacing_between = node_spacing
else:
    num_leaves_left = 2**(depth_diff - 1)
    initial_row_spacing = (num_leaves_left - 1) * (node_char_len + node_spacing) + math.floor(node_char_len / 2)
    num_nodes_between = 2**depth_diff
    spacing_between = (num_nodes_between - 2) * (node_char_len + node_spacing) + 1 + (node_char_len - 1)

       0
   6       4
      6   2   4
   2 4 8 7

       0
   6       4
     6   2   4
0 0 2 4 8 7

       0
   6       4
   6   2   4
    2 4 8 7


"""