 template<typename T>
 int lower_bound(const vector<T>& v, const T& val) {
   int l = 0, r = v.size() - 1, mid = (l + r) / 2;
   while (l != r) {
     v[mid] > val ? r = mid - 1 : l = mid;
     mid = (l + r + 1) / 2;
   }
   return mid;
 }

 template<typename T>
 int upper_bound(const vector<T>& v, const T& val) {
   int l = 0, r = v.size() - 1, mid = (l + r) / 2;
   while (l != r) {
     v[mid] < val ? l = mid + 1 : r = mid;
     mid = (l + r) / 2;
   }
   return mid;
 }