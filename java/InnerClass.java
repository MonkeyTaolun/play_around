import java.util.*; 
public class InnerClass {
  class Inner {
    double t;
    double getT() {
      return this.t;
    }
    Inner(double t) {
      this.t = t;
    }
    Inner() {
      System.out.println("I am the default constructor!");
    }
  }

  ArrayList<Inner> points;
  public InnerClass() {
    points  = new ArrayList<Inner> ();
    for ( int a = 0; a < 10; ++a) {
      points.add(new Inner(a * 1.0));
    }
  }
  
  public void print() {
    for ( Inner e : points) {
      System.out.print(e.getT() + " "); 
    }
  }

  public static void main(String args[]) {
    InnerClass ic = new InnerClass();
    ic.print();
  }
}

