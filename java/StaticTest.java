/*
 * 
 */
public class StaticTest {
  double _data  [][]  = new double [4][4];
  // System.out.println("what's this will be create!");

  public static void setData(double data [][]) {
    for ( int i = 0; i < 4; ++i) {
      for ( int j = 0; j < 4; ++j) {
        data[i][j] = i * 4 + j;
      }
    }
  }
  
  public void test1() {
    setData(this._data);
    matrixPrint();
  }

  public void matrixPrint() {
    for ( int i = 0; i < 4; ++i) {
      for ( int j = 0; j < 4; ++j) {
        System.out.print(_data[i][j] + " ");
      }
      System.out.println();
    }
  }

  public StaticTest() {
    for ( int i = 0; i < 4; ++i) {
      for ( int j = 0; j < 4; ++j) {
        _data[i][j] = 0;
      }
    }
    for ( int i = 0; i < 4; ++i) {
      for ( int j = 0; j < 4; ++j) {
        System.out.print(_data[i][j] + " ");
      }
      System.out.println();
    }
  }

  public static void main(String args[]) {
    StaticTest st = new StaticTest();
    st.test1();
    st.matrixPrint();
  }
}

