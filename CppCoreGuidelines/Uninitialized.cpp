// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es20-always-initialize-an-object

namespace uninitialized {

int bad(int val) {
  int i;
  if (val > 0) {
    i = 2;
  }
  return i;
}

int good(int val) {
  int i = 0;
  if (val > 0) {
    i = 2;
  }
  return i;
}
} // namespace uninitialized
