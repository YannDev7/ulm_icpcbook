/**
 * Author: Yann Viegas
 * Date: 27 brumaire an 234
 * License: CC0
 * Source: whatever
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 *  Useful for dynamic programming (``convex hull trick''). Generalises to other families of curves such as qudratics.
 * Time: O(\log N)
 * Status: tested on Euro (pb france IOI)
 */
#pragma once

const int TREE_SIZE = (1 << 16);
struct Line {
    int m, p;
    Line (int mV = -1e12, int pV = -1e12) { m = mV, p = pV; }
    int calc(int x) {
        return m * x + p;
    }
} tree[2 * TREE_SIZE + 42];

void insertLine(int node, int left, int right, Line newLine) {
    int mid = (left + right) / 2;
    bool bigLeft = (newLine.calc(left) > tree[node].calc(left));
    bool bigMid = (newLine.calc(mid) > tree[node].calc(mid));
    if (bigMid)
        swap(tree[node], newLine);
    if (right == left)
        return;
    if (bigLeft != bigMid)
        insertLine(2 * node, left, mid, newLine);
    else
        insertLine(2 * node + 1, mid + 1, right, newLine);
}
int getMax(int node, int left, int right, int idx) {
    if (right == left) return tree[node].calc(idx);
    int mid = (left + right) / 2;
    if (idx <= mid)
        return max(getMax(2 * node, left, mid, idx), tree[node].calc(idx));
    return max(getMax(2 * node + 1, mid + 1, right, idx), tree[node].calc(idx));
}