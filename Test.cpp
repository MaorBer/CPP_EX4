// maorw9@gmail.com
// 212305965

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <ostream>
#include "doctest.h"
#include "Tree.cpp"
#include "Complex.cpp"

TEST_CASE("Test BFS")
{

    Tree<double> tree;

    tree.add_root(1.1);
    tree.add_sub_node(1.1, 1.2);
    tree.add_sub_node(1.1, 1.3);
    tree.add_sub_node(1.2, 1.4);
    tree.add_sub_node(1.2, 1.5);
    tree.add_sub_node(1.3, 1.6);
    tree.add_sub_node(1.4, 1.7);

    vector<double> bfs1;
    for (auto node = tree.begin_BFS(); node != tree.end_BFS(); ++node)
    {
        bfs1.push_back(**node);
    }
    vector<double> expected1 = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
    CHECK((bfs1 == expected1));

    Tree<unsigned int, 4> tree2;

    tree2.add_root(1);
    tree2.add_sub_node(1, 2);
    tree2.add_sub_node(1, 3);
    tree2.add_sub_node(1, 4);
    tree2.add_sub_node(2, 5);
    tree2.add_sub_node(2, 51);
    tree2.add_sub_node(2, 52);
    tree2.add_sub_node(3, 6);
    tree2.add_sub_node(4, 7);

    vector<unsigned int> bfs2;
    for (auto node = tree2.begin_BFS(); node != tree2.end_BFS(); ++node)
    {
        bfs2.push_back(**node);
    }
    vector<unsigned int> expected2 = {1, 2, 3, 4, 5, 51, 52, 6, 7};
    CHECK((bfs2 == expected2));
}

TEST_CASE("Test DFS")
{

    Tree<double> tree;

    tree.add_root(1.1);
    tree.add_sub_node(1.1, 1.2);
    tree.add_sub_node(1.1, 1.3);
    tree.add_sub_node(1.2, 1.4);
    tree.add_sub_node(1.2, 1.5);
    tree.add_sub_node(1.3, 1.6);
    tree.add_sub_node(1.4, 1.7);

    vector<double> dfs1;
    for (auto node = tree.begin_DFS(); node != tree.end_DFS(); ++node)
    {
        dfs1.push_back(**node);
    }
    vector<double> expected1 = {1.7, 1.4, 1.5, 1.2, 1.6, 1.3, 1.1};
    CHECK((dfs1 == expected1));

    Tree<unsigned int, 4> tree2;

    tree2.add_root(1);
    tree2.add_sub_node(1, 2);
    tree2.add_sub_node(1, 3);
    tree2.add_sub_node(1, 4);
    tree2.add_sub_node(2, 5);
    tree2.add_sub_node(2, 51);
    tree2.add_sub_node(2, 52);
    tree2.add_sub_node(3, 6);
    tree2.add_sub_node(4, 7);

    vector<unsigned int> dfs2;
    for (auto node = tree2.begin_DFS(); node != tree2.end_DFS(); ++node)
    {
        dfs2.push_back(**node);
    }
    vector<unsigned int> expected2 = {5, 51, 52, 2, 6, 3, 7, 4, 1};
    CHECK((dfs2 == expected2));
}

TEST_CASE("Test Preorder")
{

    Tree<double> tree1;

    tree1.add_root(1.1);
    tree1.add_sub_node(1.1, 1.2);
    tree1.add_sub_node(1.1, 1.3);
    tree1.add_sub_node(1.2, 1.4);
    tree1.add_sub_node(1.2, 1.5);
    tree1.add_sub_node(1.3, 1.6);
    tree1.add_sub_node(1.4, 1.7);

    vector<double> preorder1;
    for (auto node = tree1.begin_PreOrder(); node != tree1.end_PreOrder(); ++node)
    {
        preorder1.push_back(**node);
    }
    vector<double> expected1 = {1.1, 1.2, 1.4, 1.7, 1.5, 1.3, 1.6};
    CHECK((preorder1 == expected1));

    Tree<unsigned int, 4> tree2;

    tree2.add_root(1);
    tree2.add_sub_node(1, 2);
    tree2.add_sub_node(1, 3);
    tree2.add_sub_node(1, 4);
    tree2.add_sub_node(2, 5);
    tree2.add_sub_node(2, 51);
    tree2.add_sub_node(2, 52);
    tree2.add_sub_node(3, 6);
    tree2.add_sub_node(4, 7);

    vector<unsigned int> preorder2;
    for (auto node = tree2.begin_PreOrder(); node != tree2.end_PreOrder(); ++node)
    {
        preorder2.push_back(**node);
    }
    vector<unsigned int> expected2 = {1, 2, 5, 51, 52, 3, 6, 4, 7};
    CHECK((preorder2 == expected2));
}

TEST_CASE("Test Inorder")
{

    Tree<double> tree1;

    tree1.add_root(1.1);
    tree1.add_sub_node(1.1, 1.2);
    tree1.add_sub_node(1.1, 1.3);
    tree1.add_sub_node(1.2, 1.4);
    tree1.add_sub_node(1.2, 1.5);
    tree1.add_sub_node(1.3, 1.6);
    tree1.add_sub_node(1.4, 1.7);

    vector<double> inorder1;
    for (auto node = tree1.begin_InOrder(); node != tree1.end_InOrder(); ++node)
    {
        inorder1.push_back(**node);
    }

    vector<double> expected1 = {1.4, 1.7, 1.4, 1.2, 1.5, 1.2, 1.5, 1.1, 1.3, 1.6, 1.3, 1.1, 1.3 , 1.6, 1.3};
    CHECK((inorder1 == expected1));

    Tree<int, 4> tree2;

    tree2.add_root(1);
    tree2.add_sub_node(1, 2);
    tree2.add_sub_node(1, 3);
    tree2.add_sub_node(1, 4);
    tree2.add_sub_node(2, 5);
    tree2.add_sub_node(2, 51);
    tree2.add_sub_node(2, 52);
    tree2.add_sub_node(3, 6);
    tree2.add_sub_node(4, 7);

    vector<int> inorder2;
    for (auto node = tree2.begin_InOrder(); node != tree2.end_InOrder(); ++node)
    {
        inorder2.push_back(**node);
    }

    vector<int> expected2 = {5, 2, 51, 52, 2, 1, 3, 6, 3, 4, 7, 4, 1};
    CHECK((inorder2 == expected2));
}

TEST_CASE("Test Postorder")
{

    Tree<double> tree;

    tree.add_root(1.1);
    tree.add_sub_node(1.1, 1.2);
    tree.add_sub_node(1.1, 1.3);
    tree.add_sub_node(1.2, 1.4);
    tree.add_sub_node(1.2, 1.5);
    tree.add_sub_node(1.3, 1.6);
    tree.add_sub_node(1.4, 1.7);

    vector<double> postorder1;
    for (auto node = tree.begin_PostOrder(); node != tree.end_PostOrder(); ++node)
    {
        postorder1.push_back(**node);
    }
    vector<double> expected1 = {1.7, 1.4, 1.5, 1.2, 1.6, 1.3, 1.1};
    CHECK((postorder1 == expected1));

    Tree<unsigned int, 4> tree2;

    tree2.add_root(1);
    tree2.add_sub_node(1, 2);
    tree2.add_sub_node(1, 3);
    tree2.add_sub_node(1, 4);
    tree2.add_sub_node(2, 5);
    tree2.add_sub_node(2, 51);
    tree2.add_sub_node(2, 52);
    tree2.add_sub_node(3, 6);
    tree2.add_sub_node(4, 7);

    vector<unsigned int> postorder2;
    for (auto node = tree2.begin_PostOrder(); node != tree2.end_PostOrder(); ++node)
    {
        postorder2.push_back(**node);
    }
    vector<unsigned int> expected2 = {5, 51, 52, 2, 6, 3, 7, 4, 1};
    CHECK((postorder2 == expected2));
}

TEST_CASE("Test heap")
{

    Tree<unsigned int, 2> tree;

    tree.add_root(1);
    tree.add_sub_node(1, 2);
    tree.add_sub_node(1, 3);
    tree.add_sub_node(2, 4);
    tree.add_sub_node(2, 5);
    tree.add_sub_node(3, 6);
    tree.add_sub_node(4, 7);

    vector<unsigned int> heap;
    for (auto node = tree.begin_Heap(); node != tree.end_Heap(); ++node)
    {
        heap.push_back(**node);
    }
    vector<unsigned int> expected = {1, 2, 3, 4, 5, 6, 7};
    CHECK((heap == expected));

    Tree<Complex, 2> complex_tree;
    complex_tree.add_root(Complex(1.1, 2));
    complex_tree.add_sub_node(Complex(1.1, 2), Complex(3, 4));
    complex_tree.add_sub_node(Complex(1.1, 2), Complex(5, 6));
    complex_tree.add_sub_node(Complex(3, 4), Complex(7, 8));
    complex_tree.add_sub_node(Complex(3, 4), Complex(3, 1));
    complex_tree.add_sub_node(Complex(3, 1), Complex(2, 10));

    vector<Complex> heap2;
    for (auto node = complex_tree.begin_Heap(); node != complex_tree.end_Heap(); ++node)
    {
        heap2.push_back(**node);
    }
    vector<Complex> expected2 = {Complex(1.1, 2), Complex(3, 4), Complex(5, 6), Complex(7, 8), Complex(3, 1), Complex(2, 10)};
    std::sort(expected2.begin(), expected2.end());
    CHECK((heap2 == expected2));
}

TEST_CASE("Complex numbers")
{

    Complex c1(1, 2);
    Complex c2(-3, -4);
    Complex c3(5.4, 6.01);

    Complex sum = c1 + c2;
    CHECK((sum == Complex(-2, -2)));

    Complex diff = c1 - c2;
    CHECK((diff == Complex(4, 6)));

    Complex prod1 = c1 * c2;
    CHECK((prod1 == Complex(5, -10)));

    Complex div1 = c1 / c3;
    CHECK(div1 == Complex(0.26685, 0.0733761));
    CHECK((c1.toString() == "(1,2)"));
    CHECK((c2.toString() == "(-3,-4)"));
    CHECK((c3.toString() == "(5.4,6.01)"));

    CHECK((c2 > c1));
    CHECK((c1 < c3));
    CHECK((c1 == Complex(1, 2)));
    CHECK((c2 != c3));
}

TEST_CASE("Illegal operations")
{

    Tree<unsigned int, 3> tree;
    tree.add_root(1);
    CHECK_THROWS(tree.add_root(2));
    CHECK_THROWS(tree.add_sub_node(2, 3));
    tree.add_sub_node(1, 2);
    tree.add_sub_node(1, 3);
    tree.add_sub_node(1, 4);
    CHECK_THROWS(tree.add_sub_node(1, 10));
    CHECK_THROWS(tree.add_sub_node(2, 4));

    Tree<Complex> complex_tree;
    complex_tree.add_root(Complex(1, 2));
    complex_tree.add_sub_node(Complex(1, 2), Complex(3, 4));
    CHECK_THROWS(complex_tree.add_sub_node(Complex(1, 2), Complex(3, 4)));
    CHECK_THROWS(complex_tree.add_sub_node(Complex(1, 2), Complex(1, 2)));
    complex_tree.add_sub_node(Complex(1, 2), Complex(5, 6));
    CHECK_THROWS(complex_tree.add_sub_node(Complex(1, 2), Complex(9, 10)));
}
