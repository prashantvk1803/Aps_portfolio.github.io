#include <bits/stdc++.h>

void build(long long ind, long long low, long long high, vector<long long>& a, vector<long long>& seg) {
    if (low == high) {
        seg[ind] = a[low];
        return;
    }
    long long mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, a, seg);
    build(2 * ind + 2, mid + 1, high, a, seg);
    seg[ind] = max(seg[2 * ind + 1] ,seg[2 * ind + 2]);
}

long long query(long long ind, long long low, long long high, long long l, long long r, vector<long long>& seg) {
    if (low <= l && high <= r) {
        return seg[ind];
    }
    if (high < l || low > r) return INT_MIN;
    long long mid = (low + high) / 2;
    long long left = query(2 * ind + 1, low, mid, l, r, seg);
    long long right = query(2 * ind + 2, mid + 1, high, l, r, seg);
    return max(left , right);
}

void update(long long ind, long long low, long long high, long long node, long long val, vector<long long>& seg) {
    if (low == high) {
        seg[ind] = val;
    } else {
        long long mid = (low + high) / 2;
        if (node <= mid && node >= low) {
            update(2 * ind + 1, low, mid, node, val, seg);
        } else {
            update(2 * ind + 2, mid + 1, high, node, val, seg);
        }
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
}


int main() {
    long long n, q;
    cin >> n >> q;
    
    vector<long long> a(n);
    vector<long long> seg(4 * n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n - 1, a, seg);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            long long k, u;
            cin >> k >> u;
            update(0, 0, n - 1, k - 1, u, seg);
        } else if (type == 2) {
            long long l, r;
            cin >> l >> r;
            cout << query(0, 0, n - 1, l - 1, r - 1, seg) << "\n";
        }
    }
    return 0;
}
