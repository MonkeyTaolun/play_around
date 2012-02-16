class Foo {
	private static volatile Bar bar = null;
	public static Bar getBar() {
	  if (bar == null) {
	    synchronized(Foo.class) {
	      if (bar == null) {
	        bar = new Bar();
	      }
	    }
	  }
	  return bar;
	}
}