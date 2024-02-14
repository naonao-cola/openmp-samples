/*
* @@name:	private.2
* @@type:	C
* @@operation:	compile
* @@expect:	unspecified
* @@version:	pre_omp_3.0
*/
int a;

void g(int k) {
  a = k; /* Accessed in the region but outside of the construct;
          * therefore unspecified whether original or private list
          * item is modified. */
}


void f(int n) {
  int a = 0;

  #pragma omp parallel for private(a)
   for (int i=1; i<n; i++) {
       a = i;
       g(a*2);     /* Private copy of "a" */
    }
}
