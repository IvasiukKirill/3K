#include <QtTest>
#include "functions.h"
// add necessary includes here

class testfunc : public QObject
{
    Q_OBJECT

public:
    testfunc();
    ~testfunc();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
};

testfunc::testfunc()
{

}

testfunc::~testfunc()
{

}

void testfunc::test_case1()
{
 QVERIFY(functions::new_param("qwe&")=="qwe" );
}

void testfunc::test_case2()
{
   QVERIFY(functions::send_stat("a")== "");

}
void testfunc::test_case3()
{
    QVERIFY(functions::validate_string("qwe")==true);
}


QTEST_APPLESS_MAIN(testfunc)

#include "tst_testfunc.moc"
