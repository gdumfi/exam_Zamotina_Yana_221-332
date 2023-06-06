#include <QtTest>

// add necessary includes here

class testfunc : public QObject
{
    Q_OBJECT

public:
    testfunc();
    ~testfunc();

private slots:
    void test_case();
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();
    void test_case6();
    void test_case7();
    void test_case8();
    void test_case9();
    void test_case10();
    void test_case11();
    void test_case12();
    void test_case13();
    void test_case14();
    void test_case15();
    void test_case16();
    void test_case17();
    void test_case18();
    void test_case19();
};

testfunc::testfunc()
{

}

testfunc::~testfunc()
{

}
void testfunc::test_case()
{
    QStringList params = { "0,0", "-2,4", "-2,-2" };
    QCOMPARE(first_task(params),"6");

    QStringList params1 = { "1,1", "-2,4", "-2,-2" };
    QCOMPARE(first_task(params1),"9");

    QStringList params2 = { "2,8", "-2,4", "-2,-2" };
    QCOMPARE(first_task(params2),"12");

    QStringList params3 = { "2,8", "2,4", "-2,-2" };
    QCOMPARE(first_task(params3),"8");

    QStringList params4 = { "2,8", "2,-4", "-2,-2" };
    QCOMPARE(first_task(params4),"24");

    QStringList params5 = { "2,8", "3,4", "5,2" };
    QCOMPARE(first_task(params5),"3");

    QStringList params6 = { "2,8", "3,4", "4,2"};
    QCOMPARE(first_task(params6),"1");

    QStringList params7 = { "2,8", "3,7", "5,2"};
    QCOMPARE(first_task(params7),"1");

    QStringList params8 = {"2,8", "3,7", "4,8" };
    QCOMPARE(first_task(params8),"1");

    QStringList params9 = {"2,8", "3,7", "4,10" };
    QCOMPARE(first_task(params9),"2");
}



void testfunc::test_case10()
{
    QStringList params = { "0,0", "-2,4", "-2,-2" };
    QCOMPARE(first_task(params),"13");
    QStringList params1 = { "1,1", "-2,4", "-2,-2" };
    QCOMPARE(first_task(params1),"14");

    QStringList params2 = { "2,8", "-2,4", "-2,-2" };
    QCOMPARE(first_task(params2),"23");

    QStringList params3 = { "2,8", "-2,4", "-2,-2" };
    QCOMPARE(first_task(params3),"21");

    QStringList params4 = { "2,8", "2,-4", "-2,-2" };
    QCOMPARE(first_task(params4),"27");

    QStringList params5 = { "2,8", "-2,4", "-2,-2" };
    QCOMPARE(first_task(params5),"13");

    QStringList params6 = { "2,8", "3,4", "5,2" };
    QCOMPARE(first_task(params6),"1");

    QStringList params7 = { "2,8", "3,7", "5,2" };
    QCOMPARE(first_task(params7),"12");

    QStringList params8 = { "2,8", "3,7", "4,8" };
    QCOMPARE(first_task(params8),"4");

    QStringList params9 = { "2,8", "3,7", "4,10" };
    QCOMPARE(first_task(params9),"7");
}
QTEST_APPLESS_MAIN(testfunc)

#include "tst_testfunc.moc"
