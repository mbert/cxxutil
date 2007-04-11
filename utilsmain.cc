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
 * $Date: 2007-04-11 14:06:00 $
 * $Revision: 1.6 $
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
#include "cxxutil/Getopt.hh"

#include <iostream>

static void testMVector (void);
static void testMPoint (void);
static void testMMatrix (void);
static void testGetopt(void);

int
main (void)
{
  testMVector ();
  testMPoint ();
  testMMatrix ();
  testGetopt();
  return 0;
}


static void
MVector_doTest (CxxUtil::MVector<double>&a, CxxUtil::MVector<double>&b,
                CxxUtil::MVector<double>&c)
{
  std::cout << "a: " << a;
  std::cout << std::endl;
  std::cout << "b: " << b;
  std::cout << std::endl;
  std::cout << "c: " << c;
  std::cout << std::endl;
  TEST_GEN_EQUALS (a, CxxUtil::MVector<double>(a.getDim (), 0.0));
  TEST_GEN_EQUALS (b, CxxUtil::MVector<double>(b.getDim (), 0.0));
  TEST_GEN_EQUALS (c, CxxUtil::MVector<double>(c.getDim (), 1.0));
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

  std::cout << "a: " << a;
  std::cout << std::endl;
  std::cout << "b: " << b;
  std::cout << std::endl;
  std::cout << "c: " << c;
  std::cout << std::endl;

}

static void
testMVector (void)
{
  {
    std::cout << "Testing class MVector<double> (1 dimension) ..." << std::endl;
    CxxUtil::MVector<double>a (1);
    CxxUtil::MVector<double>b (a);
    CxxUtil::MVector<double>c (1, 1.0);
    TEST_GEN_EQUALS (a, b);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 1);
    TEST_GEN_EQUALS (c.getNorm (), c.getNormQuad ());
    TEST_GEN_EQUALS (c.getSum (), 1.0);

    MVector_doTest (a, b, c);

    std::cout << "Test of MVector<double> (1 dimension) completed successfully."
	      << std::endl;
  }

  {
    std::cout << "Testing class MVector<double> (3 dimensions) ..."
	      << std::endl;

    CxxUtil::MVector<double>a (3);
    CxxUtil::MVector<double>b (a);
    TEST_GEN_EQUALS (a, b);
    CxxUtil::MVector<double>c (3, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 3);
    TEST_DBL_EQUALS (c.getNorm (), sqrt ((double) c.getNormQuad ()));
    TEST_GEN_EQUALS (c.getSum (), 3.0);

    MVector_doTest (a, b, c);

    std::cout << "Test of MVector<double> (3 dims) completed successfully."
	      << std::endl;
  }

  {
    std::cout << "Testing class MVector2D<double> ..." << std::endl;

    CxxUtil::MVector2D<double>a;
    CxxUtil::MVector2D<double>b (a);
    TEST_GEN_EQUALS (a, b);
    CxxUtil::MV2D c (1.0, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 2);
    TEST_DBL_EQUALS (c.getNorm (), sqrt ((double) c.getNormQuad ()));
    TEST_GEN_EQUALS (c.getSum (), 2.0);

    MVector_doTest (a, b, c);
    CxxUtil::MVector2D<double>tmp = a.getOrthogonal ();
    TEST_DBL_EQUALS (tmp[0], -a[1]);
    TEST_DBL_EQUALS (tmp[1], a[0]);
    tmp = b.getOrthogonal ();
    TEST_DBL_EQUALS (tmp[0], -b[1]);
    TEST_DBL_EQUALS (tmp[1], b[0]);
    tmp = c.getOrthogonal ();
    TEST_DBL_EQUALS (tmp[0], -c[1]);
    TEST_DBL_EQUALS (tmp[1], c[0]);

    std::cout << "Test of MVector2D<double> completed successfully."
	      << std::endl;
  }

  {
    std::cout << "Testing class MVector3D<double> ..." << std::endl;

    CxxUtil::MVector3D<double>a;
    CxxUtil::MVector3D<double>b (a);
    TEST_GEN_EQUALS (a, b);
    CxxUtil::MV3D c (1.0, 1.0, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 3);
    TEST_DBL_EQUALS (c.getNorm (), sqrt (c.getNormQuad ()));
    TEST_GEN_EQUALS (c.getSum (), 3.0);

    MVector_doTest (a, b, c);

    // @todo Test the cross product properly!
    CxxUtil::MV3D e (1.0, 0.0, 0.0);
    CxxUtil::MV3D f (0.0, 1.0, 0.0);

    TEST_GEN_EQUALS (e ^ f, CxxUtil::MV3D (0, 0, 1));

    e[1] = 1;
    f[2] = 2;

    TEST_GEN_EQUALS (e ^ f, CxxUtil::MV3D (2, -2, 1));

    std::cout << "Test of MVector3D<double> completed successfully."
	      << std::endl;
  }

  {
    std::cout << "Testing class MVector4D<double> ..." << std::endl;

    CxxUtil::MVector4D<double>a;
    CxxUtil::MVector4D<double>b (a);
    TEST_GEN_EQUALS (a, b);
    CxxUtil::MV4D c (1.0, 1.0, 1.0, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 4);
    TEST_DBL_EQUALS (c.getNorm (), sqrt ((double) c.getNormQuad ()));
    TEST_GEN_EQUALS (c.getSum (), 4.0);

    MVector_doTest (a, b, c);

    std::cout << "Test of MVector4D<double> completed successfully."
	      << std::endl;
  }
}

static void
MPoint_doTest (CxxUtil::MPoint<double>&a, CxxUtil::MPoint<double>&b,
	       CxxUtil::MPoint<double>&c)
{
  std::cout << "a: " << a;
  std::cout << std::endl;
  std::cout << "b: " << b;
  std::cout << std::endl;
  std::cout << "c: " << c;
  std::cout << std::endl;
  TEST_GEN_EQUALS (a, CxxUtil::MPoint<double>(a.getDim (), 0.0));
  TEST_GEN_EQUALS (b, CxxUtil::MPoint<double>(b.getDim (), 0.0));
  TEST_GEN_EQUALS (c, CxxUtil::MPoint<double>(c.getDim (), 1.0));
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
  std::cout << "a: " << a;
  std::cout << std::endl;
  std::cout << "b: " << b;
  std::cout << std::endl;
  std::cout << "c: " << c;
  std::cout << std::endl;

  std::cout << "affineComb2 () ... " << affineComb2 (0.25, a, b) << std::endl;
  TEST_GEN_EQUALS (affineComb2 (0.25, a, b),
                   CxxUtil::MPoint<double>(a.getDim (), 1.25));
  std::cout << "OK" << std::endl;

  std::cout << "affineComb3 () ... ";
  TEST_GEN_EQUALS (affineComb3 (0.25, a, 0.50, b, 0.25, c),
                   CxxUtil::MPoint<double>(a.getDim (), 1.5));
  std::cout << "OK" << std::endl;
  std::cout << "dist(a, b) == dist(a, c)";
  TEST_DBL_EQUALS (a.dist (b), b.dist (c));
  std::cout << ", dist(a, b) == sqrt(dim (a))";
  TEST_DBL_EQUALS (a.dist (b), sqrt ((double) a.getDim ()));
  std::cout << ", dist(a, c) == 0";
  TEST_DBL_EQUALS (a.dist (c), 0.0);
  std::cout << " ... OK" << std::endl;
  std::cout << "a: " << a;
  std::cout << std::endl;
  std::cout << "b: " << b;
  std::cout << std::endl;
  std::cout << "c: " << c;
  std::cout << std::endl;
}

static void
testMPoint (void)
{
  {
    std::cout << "Testing class MPoint<double> (1 dimension) ..." << std::endl;

    CxxUtil::MPoint<double>a (1);
    CxxUtil::MPoint<double>b (a);
    TEST_GEN_EQUALS (a, b);
    CxxUtil::MPoint<double>c (1, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 1);
    TEST_DBL_EQUALS (c.getSum (), 1.0);

    MPoint_doTest (a, b, c);

    std::cout << "Test of MPoint<double> (1 dimension) completed successfully."
	      << std::endl;
  }

  {
    std::cout << "Testing class MPoint<double> (3 dimensions) ..." << std::endl;

    CxxUtil::MPoint<double>a (3);
    CxxUtil::MPoint<double>b (a);
    TEST_GEN_EQUALS (a, b);
    CxxUtil::MPoint<double>c (3, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 3);
    TEST_DBL_EQUALS (c.getSum (), 3.0);

    MPoint_doTest (a, b, c);

    std::cout << "Test of MPoint<double> (3 dimensions) completed successfully."
	      << std::endl;
  }

  {
    std::cout << "Testing class MPoint2D<double> ..." << std::endl;

    CxxUtil::MPoint2D<double>a;
    CxxUtil::MPoint2D<double>b (a);
    TEST_GEN_EQUALS (a, b);
    CxxUtil::MP2D c (1.0, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 2);
    TEST_DBL_EQUALS (c.getSum (), 2.0);

    MPoint_doTest (a, b, c);

    std::cout << "Test of MPoint2D completed successfully." << std::endl;
  }

  {
    std::cout << "Testing class MPoint3D<double> ..." << std::endl;

    CxxUtil::MPoint3D<double>a;
    CxxUtil::MPoint3D<double>b (a);
    TEST_GEN_EQUALS (a, b);
    CxxUtil::MP3D c (1.0, 1.0, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 3);
    TEST_DBL_EQUALS (c.getSum (), 3.0);

    MPoint_doTest (a, b, c);

    std::cout << "Test of MPoint3D<double> completed successfully."
	      << std::endl;
  }

  {
    std::cout << "Testing class MPoint4D<double> ..." << std::endl;

    CxxUtil::MPoint4D<double>a;
    CxxUtil::MPoint4D<double>b (a);
    TEST_GEN_EQUALS (a, b);
    CxxUtil::MP4D c (1.0, 1.0, 1.0, 1.0);
    TEST_GEN_DIFFERS (c, a);
    TEST_GEN_DIFFERS (c, b);

    TEST_GEN_EQUALS (a.getDim (), 4);
    TEST_DBL_EQUALS (c.getSum (), 4.0);

    MPoint_doTest (a, b, c);

    CxxUtil::MP3D d = c.projectTo3D ();
    TEST_GEN_EQUALS (d, CxxUtil::MP3D (1.0, 1.0, 1.0));

    d = b.projectTo3D ();
    TEST_GEN_EQUALS (d, CxxUtil::MP3D (1.0, 1.0, 1.0));

    std::cout << "Test of MPoint4D completed successfully." << std::endl;
  }
}

static void
testMMatrix (void)
{
  std::cout << "Testing class MMatrix<double> ..." << std::endl;
  CxxUtil::MMatrix<double>m1 (4, 4);
  TEST_GEN_EQUALS (m1.cols (), 4);
  TEST_GEN_EQUALS (m1.rows (), 4);
  CxxUtil::MMatrix<double>m2 = m1;
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

  CxxUtil::MMatrix<double>m3 (3, 2, 1);
  CxxUtil::MVector<double>v1 (2, 2);
  CxxUtil::MVector<double>v2 (3, 2);
  CxxUtil::MVector<double>v3;
  TEST_EXCEPTION (v3 = m3 * v2);
  v3 = m3 * v1;
  TEST_GEN_EQUALS (v3, CxxUtil::MVector<double>(3, 4));
  m2 = m3;
  TEST_GEN_EQUALS (m2, m3);

  CxxUtil::MMatrix4x4<double>m4 (0);
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

  CxxUtil::MMatrix<double>ma (2, 4);
  for (int y = 0; y < ma.rows (); y++)
    {
      for (int x = 0; x < ma.cols (); x++)
        {
          ma (y, x) = y * ma.cols () + x + 1;
        }
    }
  std::cout << ma << std::endl;

  CxxUtil::MMatrix<double>mb (4, 3);
  for (int y = 0; y < mb.rows (); y++)
    {
      for (int x = 0; x < mb.cols (); x++)
        {
          mb (y, x) = y * mb.cols () + x + 1;
        }
    }
  std::cout << mb << std::endl;

  TEST_DBL_DIFFERS (ma.cols (), m2.rows ());
  TEST_EXCEPTION (m1 = ma * m2);
  TEST_DBL_EQUALS (ma.cols (), mb.rows ());

  CxxUtil::MMatrix<double>mc (2, 3);
  mc (0, 0) = 70;
  mc (0, 1) = 80;
  mc (0, 2) = 90;
  mc (1, 0) = 158;
  mc (1, 1) = 184;
  mc (1, 2) = 210;

  m1 = ma * mb;
  std::cout << m1 << std::endl;
  TEST_GEN_EQUALS (m1, mc);

  TEST_EXCEPTION (ma | m2);
  TEST_EXCEPTION (ma + m2);
  TEST_EXCEPTION (ma - m2);

  TEST_DBL_EQUALS (ma | ma, 204);

  TEST_GEN_EQUALS (m2 + m3, m2 * 2);
  TEST_GEN_EQUALS (m2 - m3, m2 * 0);
  TEST_GEN_EQUALS (m2 * 2, m2 / 0.5);

  std::cout << "Test of MMatrix<double>  completed successfully." << std::endl;
}

static char *argv[] = {
  "getopttest",
  "-c", "die",
  "-p", "/home/user/src/foo/bar/foobar/",
  "first-non-op",
  NULL
};
static char *onlyswitches[] = {
  "getopttest",
  "-c", "die",
  "-p", "/home/user/src/foo/bar/foobar/",
  "-x",
  NULL
};
static char *nonops[] = {
  "this",
  "has",
  "no",
  "options",
  "and",
  "segfaults",
  NULL
};

static char **g_argv;
static char **g_noops;
static char **g_onlyswitches;
static int g_argc;
static char *g_optionstring;
static CxxUtil::Getopt *oOption;
static CxxUtil::Getopt *pOption;
static CxxUtil::Getopt *sOption;


static void
Getopt_testConstructor(void)
{
  TEST_ASSERT(oOption = new CxxUtil::Getopt(true));
  TEST_ASSERT(pOption = new CxxUtil::Getopt(true));
  TEST_ASSERT(sOption = new CxxUtil::Getopt(true));
  oOption->disableWarnings();

  oOption->addOption('c', true, "-c option");
  pOption->addOption('c', true, "-c option");
  sOption->addOption('c', true, "-c option");
  oOption->addOption('p', true, "-p option");
  pOption->addOption('p', true, "-p option");
  sOption->addOption('p', true, "-p option");
  oOption->addOption('x', false, "-x");
  pOption->addOption('x', false, "-x");
  sOption->addOption('x', false, "-x");

  oOption->process(g_argc, g_argv);
  pOption->process(g_argc, g_noops);
  sOption->process(g_argc, g_onlyswitches);
}

static void
Getopt_testErrorHandling(void)
{
  TEST_ASSERT(!oOption->error());
  TEST_ASSERT(!pOption->error());
  TEST_ASSERT(!sOption->error());
}

static void
Getopt_testCommandOption(void)
{
  TEST_ASSERT(oOption->given("c"));
  TEST_ASSERT(oOption->opt("c").getValue() == "die");
}

static void
Getopt_testPathOption(void)
{
  if (oOption->given("p"))
    {
      TEST_ASSERT(oOption->opt("p").getValue() == argv[4]);
    }
}

static void
Getopt_testProgArg(void)
{
  //cerr << "*** " << argv[oOption->firstNonOp()] << std::endl;
  TEST_ASSERT(argv[oOption->firstNonOp()] != NULL);
  TEST_ASSERT(g_noops[pOption->firstNonOp()] != NULL);
  TEST_ASSERT(g_onlyswitches[sOption->firstNonOp()] == NULL);
  TEST_GEN_EQUALS(argv[oOption->firstNonOp()], "first-non-op");
  TEST_GEN_EQUALS(g_noops[pOption->firstNonOp()], "has");
}

static void
testGetopt(void)
{
  std::cout << "Testing class Getopt..." << std::endl;
  g_optionstring = "xc:p:";
  g_argc = 6;
  g_argv = argv;
  g_noops = nonops;
  g_onlyswitches = onlyswitches;
  Getopt_testConstructor();
  Getopt_testErrorHandling();
  Getopt_testCommandOption();
  Getopt_testPathOption();
  Getopt_testProgArg();
  std::cout << "Test of Getopt completed successfully." << std::endl;
}

