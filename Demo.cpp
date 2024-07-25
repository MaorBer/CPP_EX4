// maorw9@gmail.com
// 212305965

#include "Frontend.cpp"
#include <string>

using namespace std;
using namespace ariel;

int main()
{

    cout << "Binary tree:" << endl;
    Tree<double> tree; // Binary tree that contains doubles.

    tree.add_root(1.1);
    tree.add_sub_node(1.1, 1.2);
    tree.add_sub_node(1.1, 1.3);
    tree.add_sub_node(1.2, 1.4);
    tree.add_sub_node(1.2, 1.5);
    tree.add_sub_node(1.3, 1.6);
    tree.add_sub_node(1.4, 1.7);

    for (auto &node : tree)
    {
        cout << *node << " ";
    }
    cout << endl;
    for (auto node = tree.begin_BFS(); node != tree.end_BFS(); ++node)
    {
        cout << **node << " ";
    }
    cout << endl;
    for (auto node = tree.begin_DFS(); node != tree.end_DFS(); ++node)
    {
        cout << **node << " ";
    }
    cout << endl;
    for (auto node = tree.begin_PostOrder(); node != tree.end_PostOrder(); ++node)
    {
        cout << **node << " ";
    }
    cout << endl;

    display(tree);

    //    tree.display();
    //    tree.toHeap();
    //    tree.display();

    Tree<unsigned int, 3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(1);
    three_ary_tree.add_sub_node(1, 2);
    three_ary_tree.add_sub_node(1, 3);
    three_ary_tree.add_sub_node(1, 4);
    three_ary_tree.add_sub_node(2, 5);
    three_ary_tree.add_sub_node(2, 51);
    three_ary_tree.add_sub_node(2, 52);
    three_ary_tree.add_sub_node(3, 6);

    display(three_ary_tree);

    //    three_ary_tree.display();

    Tree<string, 3> three_ary_tree2; // 3-ary tree.
    three_ary_tree2.add_root("1");
    three_ary_tree2.add_sub_node("1", "2");
    three_ary_tree2.add_sub_node("1", "3");
    three_ary_tree2.add_sub_node("1", "4");
    three_ary_tree2.add_sub_node("2", "5");
    three_ary_tree2.add_sub_node("2", "51");
    three_ary_tree2.add_sub_node("2", "52");
    three_ary_tree2.add_sub_node("3", "6");

    //    three_ary_tree2.display();

    Tree<Complex, 2> complex_tree;
    complex_tree.add_root(Complex(1.1, 2));
    complex_tree.add_sub_node(Complex(1.1, 2), Complex(3, 4));
    complex_tree.add_sub_node(Complex(1.1, 2), Complex(5, 6));
    complex_tree.add_sub_node(Complex(3, 4), Complex(7, 8));
    complex_tree.add_sub_node(Complex(3, 4), Complex(3, 1));
    complex_tree.add_sub_node(Complex(3, 1), Complex(2, 10));

    //    complex_tree.display();

    return 0;
}