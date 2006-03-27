/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */

/* --------------------------------------------------------------------
 * Main test program
 *
 * $Date: 2006-03-27 13:00:01 $
 * $Revision: 1.5 $
 * -------------------------------------------------------------------- */

// simple testing area
#include "cxxutil/utils.h"
#include "cxxutil/testing.h"
#include "cxxutil/MPoint2D.hh"
#include "cxxutil/MPoint3D.hh"
#include "cxxutil/MPoint4D.hh"
#include "cxxutil/MVector2D.hh"
#include "cxxutil/MVector3D.hh"
#include "cxxutil/MVector4D.hh"
#include "cxxutil/MMatrix4x4.hh"

#include <iostream>

using namespace std;
using namespace CxxUtil;

static void testMVector (void);
static void testMPoint (void);
static void testMMatrix (void);


int
main (void)
{
  testMVector ();
  testMPoint ();
  testMMatrix ();
  return 0;
}


static void
MVector_doTest (MVector<double>&a, MVector<double>&b,
                MVector<double>&c)
{
  cout << "a: " << a;
  cout << endl;
  cout << "b: " << b;
  cout << endl;
  cout << "c: " << c;
  cout << endl;
  TEST_GEN_EQUALS (a, MVector<double>(a.getDim (), 0.0));
  TEST_GEN_EQUALS (b, MVector<double>(b.getDim (), 0.0));
  TEST_GEN_EQUALS (c, MVector<double>(c.getDim (), 1.0));
  // 0, 0, 1
  a = -c;
  // -1, 0, 1
  TEST_GEN_EQUALS (-a, c);
  a = b;
  // 0, 0, 1
  TEST_GEN_EQUALS (a, b);
  a = c;
  // 1, 0, 1
  TEST_GEN_DIFFERS (a, b);
  TEST_GEN_EQUALS (a, c);
  a += b;
  // 1, 0, 1
  TEST_GEN_EQUALS (a, c);
  a = 0;
  // 0, 0, 1
  TEST_GEN_EQUALS (a, b);
  a += c;
  // 1, 0, 1
  TEST_GEN_EQUALS (a, c);
  a = b - c;
  // -1, 0, 1
  TEST_GEN_EQUALS (a, (-c));
  a += c;
  // 0, 0, 1
  TEST_GEN_EQUALS (a, b);
  a += c;
  // 1, 0, 1
  TEST_GEN_EQUALS (a, c);
  c -= a;
  // 1, 0, 0
  TEST_GEN_EQUALS (c, b);
  c = a;
  // 1, 0, 1
  c *= 2;
  // 1, 0, 2
  TEST_GEN_EQUALS (c, 2 * a);
  c /= 2;
  // 1, 0, 1
  TEST_GEN_EQUALS (a, c);
  b = a + c;
  // 1, 2, 1
  TEST_GEN_EQUALS (b, 2 * a);
  a = 2 * c;
  // 2, 2, 1
  TEST_GEN_EQUALS (a, b);
  for (int i = 0; i < a.getDim (); i++)
    {
      a[i] = c[i];
    }
  // 1, 2, 1
  TEST_GEN_EQUALS (a, c);

  TEST_DBL_EQUALS (b | c, b.getSum ());

  cout << "a: " << a;
  cout << endl;
  cout << "b: " << b;
  cout << endl;
  cout << "c: " << c;
  cout << endl;

}

static void
testMVector (void)
{
  {
    cout << "Testing class MVector<double> (1 dimension) ..." << endl;
    MVector<double>a (1);
    MVector<double>b (a);
    MVector<double>c (1, 1.0);
    TEST_GEN_EQUALS (a, b);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 1);
    TEST_GEN_EQUALS (c.getNorm (), c.getNormQuad ());
    TEST_GEN_EQUALS (c.getSum (), 1.0);

    MVector_doTest (a, b, c);

    cout << "Test of MVector<double> (1 dimension) completed successfully."
      << endl;
  }

  {
    cout << "Testing class MVector<double> (3 dimensions) ..." << endl;

    MVector<double>a (3);
    MVector<double>b (a);
    TEST_GEN_EQUALS (a, b);
    MVector<double>c (3, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 3);
    TEST_DBL_EQUALS (c.getNorm (), sqrt ((double) c.getNormQuad ()));
    TEST_GEN_EQUALS (c.getSum (), 3.0);

    MVector_doTest (a, b, c);

    cout <<
      "Test of MVector<double> (3 dimensions) completed successfully." <<
      endl;
  }

  {
    cout << "Testing class MVector2D<double> ..." << endl;

    MVector2D<double>a;
    MVector2D<double>b (a);
    TEST_GEN_EQUALS (a, b);
    MV2D c (1.0, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 2);
    TEST_DBL_EQUALS (c.getNorm (), sqrt ((double) c.getNormQuad ()));
    TEST_GEN_EQUALS (c.getSum (), 2.0);

    MVector_doTest (a, b, c);
    MVector2D<double>tmp = a.getOrthogonal ();
    TEST_DBL_EQUALS (tmp[0], -a[1]);
    TEST_DBL_EQUALS (tmp[1], a[0]);
    tmp = b.getOrthogonal ();
    TEST_DBL_EQUALS (tmp[0], -b[1]);
    TEST_DBL_EQUALS (tmp[1], b[0]);
    tmp = c.getOrthogonal ();
    TEST_DBL_EQUALS (tmp[0], -c[1]);
    TEST_DBL_EQUALS (tmp[1], c[0]);

    cout << "Test of MVector2D<double> completed successfully." << endl;
  }

  {
    cout << "Testing class MVector3D<double> ..." << endl;

    MVector3D<double>a;
    MVector3D<double>b (a);
    TEST_GEN_EQUALS (a, b);
    MV3D c (1.0, 1.0, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 3);
    TEST_DBL_EQUALS (c.getNorm (), sqrt (c.getNormQuad ()));
    TEST_GEN_EQUALS (c.getSum (), 3.0);

    MVector_doTest (a, b, c);

    // @todo Test the cross product properly!
    MV3D e (1.0, 0.0, 0.0);
    MV3D f (0.0, 1.0, 0.0);

    TEST_GEN_EQUALS (e ^ f, MV3D (0, 0, 1));

    e[1] = 1;
    f[2] = 2;

    TEST_GEN_EQUALS (e ^ f, MV3D (2, -2, 1));

    cout << "Test of MVector3D<double> completed successfully." << endl;
  }

  {
    cout << "Testing class MVector4D<double> ..." << endl;

    MVector4D<double>a;
    MVector4D<double>b (a);
    TEST_GEN_EQUALS (a, b);
    MV4D c (1.0, 1.0, 1.0, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 4);
    TEST_DBL_EQUALS (c.getNorm (), sqrt ((double) c.getNormQuad ()));
    TEST_GEN_EQUALS (c.getSum (), 4.0);

    MVector_doTest (a, b, c);

    cout << "Test of MVector4D<double> completed successfully." << endl;
  }
}

static void
MPoint_doTest (MPoint<double>&a, MPoint<double>&b, MPoint<double>&c)
{
  cout << "a: " << a;
  cout << endl;
  cout << "b: " << b;
  cout << endl;
  cout << "c: " << c;
  cout << endl;
  TEST_GEN_EQUALS (a, MPoint<double>(a.getDim (), 0.0));
  TEST_GEN_EQUALS (b, MPoint<double>(b.getDim (), 0.0));
  TEST_GEN_EQUALS (c, MPoint<double>(c.getDim (), 1.0));
  // 0, 0, 1
  a = b;
  // 0, 0, 1
  TEST_GEN_EQUALS (a, b);
  a = c;
  // 1, 0, 1
  TEST_GEN_DIFFERS (a, b);
  TEST_GEN_EQUALS (a, c);
  a += b;
  // 1, 0, 1
  TEST_GEN_EQUALS (a, c);
  a = 0;
  // 0, 0, 1
  TEST_GEN_EQUALS (a, b);
  a += c;
  // 1, 0, 1
  TEST_GEN_EQUALS (a, c);
  a = (b - c).toPoint ();
  // -1, 0, 1
  TEST_GEN_EQUALS (a, (-c));
  a = b - c.toVector ();
  // -1, 0, 1
  TEST_GEN_EQUALS (a, (-c));
  a += 1;
  // 0, 0, 1
  TEST_GEN_EQUALS (a, b);
  a += 1;
  // 1, 0, 1
  TEST_GEN_EQUALS (a, c);
  c -= a;
  // 1, 0, 0
  TEST_GEN_EQUALS (c, b);
  c += 2;
  // 1, 0, 2
  c -= 1;
  // 1, 0, 1
  TEST_GEN_EQUALS (c, a);
  b = a + c;
  // 1, 2, 1
  TEST_GEN_EQUALS (b, 2 * a);
  a = a + c;
  // 2, 2, 1
  TEST_GEN_EQUALS (b, a);
  for (int i = 0; i < a.getDim (); i++)
    {
      a[i] = c[i];
    }
  // 1, 2, 1
  TEST_GEN_EQUALS (a, c);
  cout << "a: " << a;
  cout << endl;
  cout << "b: " << b;
  cout << endl;
  cout << "c: " << c;
  cout << endl;

  cout << "affineComb2 () ... " << affineComb2 (0.25, a, b) << endl;
  TEST_GEN_EQUALS (affineComb2 (0.25, a, b),
                   MPoint<double>(a.getDim (), 1.25));
  cout << "OK" << endl;

  cout << "affineComb3 () ... ";
  TEST_GEN_EQUALS (affineComb3 (0.25, a, 0.50, b, 0.25, c),
                   MPoint<double>(a.getDim (), 1.5));
  cout << "OK" << endl;
  cout << "dist(a, b) == dist(a, c)";
  TEST_DBL_EQUALS (a.dist (b), b.dist (c));
  cout << ", dist(a, b) == sqrt(dim (a))";
  TEST_DBL_EQUALS (a.dist (b), sqrt ((double) a.getDim ()));
  cout << ", dist(a, c) == 0";
  TEST_DBL_EQUALS (a.dist (c), 0.0);
  cout << " ... OK" << endl;
  cout << "a: " << a;
  cout << endl;
  cout << "b: " << b;
  cout << endl;
  cout << "c: " << c;
  cout << endl;
}

static void
testMPoint (void)
{
  {
    cout << "Testing class MPoint<double> (1 dimension) ..." << endl;

    MPoint<double>a (1);
    MPoint<double>b (a);
    TEST_GEN_EQUALS (a, b);
    MPoint<double>c (1, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 1);
    TEST_DBL_EQUALS (c.getSum (), 1.0);

    MPoint_doTest (a, b, c);

    cout << "Test of MPoint<double> (1 dimension) completed successfully."
      << endl;
  }

  {
    cout << "Testing class MPoint<double> (3 dimensions) ..." << endl;

    MPoint<double>a (3);
    MPoint<double>b (a);
    TEST_GEN_EQUALS (a, b);
    MPoint<double>c (3, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 3);
    TEST_DBL_EQUALS (c.getSum (), 3.0);

    MPoint_doTest (a, b, c);

    cout << "Test of MPoint<double> (3 dimensions) completed successfully."
      << endl;
  }

  {
    cout << "Testing class MPoint2D<double> ..." << endl;

    MPoint2D<double>a;
    MPoint2D<double>b (a);
    TEST_GEN_EQUALS (a, b);
    MP2D c (1.0, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 2);
    TEST_DBL_EQUALS (c.getSum (), 2.0);

    MPoint_doTest (a, b, c);

    cout << "Test of MPoint2D completed successfully." << endl;
  }

  {
    cout << "Testing class MPoint3D<double> ..." << endl;

    MPoint3D<double>a;
    MPoint3D<double>b (a);
    TEST_GEN_EQUALS (a, b);
    MP3D c (1.0, 1.0, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 3);
    TEST_DBL_EQUALS (c.getSum (), 3.0);

    MPoint_doTest (a, b, c);

    cout << "Test of MPoint3D<double> completed successfully." << endl;
  }

  {
    cout << "Testing class MPoint4D<double> ..." << endl;

    MPoint4D<double>a;
    MPoint4D<double>b (a);
    TEST_GEN_EQUALS (a, b);
    MP4D c (1.0, 1.0, 1.0, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 4);
    TEST_DBL_EQUALS (c.getSum (), 4.0);

    MPoint_doTest (a, b, c);

    MP3D d = c.projectTo3D ();
    TEST_GEN_EQUALS (d, MP3D (1.0, 1.0, 1.0));

    d = b.projectTo3D ();
    TEST_GEN_EQUALS (d, MP3D (1.0, 1.0, 1.0));

    cout << "Test of MPoint4D completed successfully." << endl;
  }
}

static void
testMMatrix (void)
{
  cout << "Testing class MMatrix<double> ..." << endl;
  MMatrix<double>m1 (4, 4);
  TEST_GEN_EQUALS (m1.cols (), 4);
  TEST_GEN_EQUALS (m1.rows (), 4);
  MMatrix<double>m2 = m1;
  TEST_GEN_EQUALS (m1, m2);
  TEST_ASSERT (!(m1 != m2));
  m2.fill (42);
  TEST_GEN_DIFFERS (m1, m2);
  TEST_ASSERT (!(m1 == m2));
  m2 (3, 3) = 0;
  TEST_DBL_EQUALS (m2 (3, 3), 0);
  TEST_DBL_EQUALS (m2 (3, 2), 42);
  TEST_DBL_EQUALS (m2 (2, 3), 42);
  TEST_DBL_EQUALS (m2 (2, 2), 42);

  MMatrix<double>m3 (3, 2, 1);
  MVector<double>v1 (2, 2);
  MVector<double>v2 (3, 2);
  MVector<double>v3;
  TEST_EXCEPTION (v3 = m3 * v2);
  v3 = m3 * v1;
  TEST_GEN_EQUALS (v3, MVector<double>(3, 4));
  m2 = m3;
  TEST_GEN_EQUALS (m2, m3);

  MMatrix4x4<double>m4 (0);
  double a[4][4];

  for (int y = 0; y < 4; y++)
    {
      for (int x = 0; x < 4; x++)
        {
          a[x][y] = x + y;
        }
    }

  m4.fromA (a);

  for (int y = 0; y < 4; y++)
    {
      for (int x = 0; x < 4; x++)
        {
          TEST_DBL_EQUALS (m4 (y, x) - x, y);
          TEST_DBL_EQUALS (m4 (y, x) - y, x);
        }
    }

  MMatrix<double>ma (2, 4);
  for (int y = 0; y < ma.rows (); y++)
    {
      for (int x = 0; x < ma.cols (); x++)
        {
          ma (y, x) = y * ma.cols () + x + 1;
        }
    }
  cout << ma << endl;

  MMatrix<double>mb (4, 3);
  for (int y = 0; y < mb.rows (); y++)
    {
      for (int x = 0; x < mb.cols (); x++)
        {
          mb (y, x) = y * mb.cols () + x + 1;
        }
    }
  cout << mb << endl;

  TEST_DBL_DIFFERS (ma.cols (), m2.rows ());
  TEST_EXCEPTION (m1 = ma * m2);
  TEST_DBL_EQUALS (ma.cols (), mb.rows ());

  MMatrix<double>mc (2, 3);
  mc (0, 0) = 70;
  mc (0, 1) = 80;
  mc (0, 2) = 90;
  mc (1, 0) = 158;
  mc (1, 1) = 184;
  mc (1, 2) = 210;

  m1 = ma * mb;
  cout << m1 << endl;
  TEST_GEN_EQUALS (m1, mc);

  TEST_EXCEPTION (ma | m2);
  TEST_EXCEPTION (ma + m2);
  TEST_EXCEPTION (ma - m2);

  TEST_DBL_EQUALS (ma | ma, 204);

  TEST_GEN_EQUALS (m2 + m3, m2 * 2);
  TEST_GEN_EQUALS (m2 - m3, m2 * 0);
  TEST_GEN_EQUALS (m2 * 2, m2 / 0.5);

  cout << "Test of MMatrix<double>  completed successfully." << endl;
}
