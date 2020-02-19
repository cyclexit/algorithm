typedef long long ll;
typedef const long long& cllr;

const ll N = ...; // TODO: set max size
struct Seg {
  ll l, r, v;
} t[4*N];
ll n, m, a[N], lz[4*N], ...; // TODO: add more lazy tags if needed

inline void up(cllr i) {
  // TODO: change
  t[i].v = t[i<<1].v + t[i<<1|1].v;
}

void down(cllr i) {
  // TODO: change
  lz[i<<1] += lz[i];
  lz[i<<1|1] += lz[i];
  ll left = t[i].l, right = t[i].r;
  ll mid = (left + right) >> 1;
  t[i<<1].v += lz[i] * (mid - left + 1);
  t[i<<1|1].v += lz[i] * (right - mid);
  lz[i] = 0;
  up(i);
}

void build(cllr i, cllr l, cllr r) {
  t[i].l = l;
  t[i].r = r;
  if (l == r) {
    t[i].v = a[l];
    return;
  }
  ll mid = (l + r) >> 1;
  build(i<<1, l, mid);
  build(i<<1|1, mid+1, r);
  up(i);
}

// update operation
void update(cllr i, cllr l, cllr r, cllr v) {
  if (l <= t[i].l && t[i].r <= r) {
    // TODO: change
    t[i].v += (t[i].r - t[i].l + 1) * v;
    lz[i] += v;
    return;
  }
  down(i);
  ll mid = (t[i].r + t[i].l) >> 1;
  if (l <= mid) update(i<<1, l, r, v);
  if (r > mid) update(i<<1|1, l, r, v);
  up(i);
}

// query operation
ll query(cllr i, cllr l, cllr r) {
  if (l <= t[i].l && t[i].r <= r) {
    return t[i].v;
  }
  ll mid = (t[i].r + t[i].l) >> 1;
  down(i);
  ll res = 0;
  // TODO: change
  if (l <= mid) res += query(i<<1, l, r);
  if (r > mid) res += query(i<<1|1, l, r);
  return res;
}