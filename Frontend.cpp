// maorw9@gmail.com
// 212305965

#ifndef FRONTEND_HPP
#define FRONTEND_HPP

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGuiApplication>
#include <QScreen>
#include <QTextEdit>
#include "Tree.cpp"
#include "Complex.cpp"

namespace ariel {

using std::string;

// Define constants
#define VERTICAL_SPACING 120  // Adjusted vertical spacing
#define NODE_RADIUS 35        // Adjusted node radius

/**
 * Converts a value to a QString.
 */
template <typename T>
QString toQString(T value)
{
    string value_string = std::to_string(value);
    return QString::fromStdString(value_string);
}

/**
 * Specialization for double to remove trailing zeros.
 */
template <>
inline QString toQString<double>(double value)
{
    string value_string = std::to_string(value);
    while (value_string.back() == '0')
        value_string.pop_back();
    return QString::fromStdString(value_string);
}

/**
 * Specialization for std::string.
 */
template <>
inline QString toQString<string>(string value)
{
    return QString::fromStdString(value);
}

/**
 * Specialization for Complex type.
 */
template <>
inline QString toQString<Complex>(Complex value)
{
    string str = value.toString();
    return QString::fromStdString(str);
}

/**
 * Screen class to display the tree in a GUI.
 * T - type of the tree node values
 * D - number of children per node (degree of the tree)
 */
template <typename T, unsigned int D>
class Screen
{
    QApplication *my_app;          // Qt application instance
    QMainWindow *main_window;      // Main window
    Tree<T, D> *my_tree;           // Tree to display
    QGraphicsView *my_view;        // View to display the tree graphics
    QGraphicsScene *my_scene;      // Scene to manage the tree graphics
    int screen_width;              // Screen width
    int screen_height;             // Screen height

    QPushButton *bfs_button;       // Button for BFS traversal
    QPushButton *dfs_button;       // Button for DFS traversal
    QPushButton *pre_order_button; // Button for Pre-Order traversal
    QPushButton *in_order_button;  // Button for In-Order traversal
    QPushButton *post_order_button;// Button for Post-Order traversal
    QPushButton *heap_button;      // Button for Heap transformation
    QTextEdit *text_box;           // Text box to display traversal output

public:
    /**
     * Constructor for the Screen class.
     * Initializes the application, main window, and buttons.
     */
    Screen(Tree<T, D> &tree)
    {
        int argc = 1;
        char letter = 'M';
        char *pointer = &letter;
        char *argv[1] = {pointer};
        my_app = new QApplication(argc, argv);

        // Create the main window
        main_window = new QMainWindow();
        main_window->setWindowTitle("EX4 SP by Maor Berenstein");
        main_window->showMaximized();
        my_scene = new QGraphicsScene(main_window);
        my_view = new QGraphicsView(my_scene, main_window);
        my_view->setRenderHint(QPainter::Antialiasing);
        main_window->setCentralWidget(my_view);
        QScreen *my_screen = QGuiApplication::primaryScreen();
        QRect screen_geometry = my_screen->geometry();

        screen_width = screen_geometry.width() * 0.75;
        screen_height = screen_geometry.height();

        // Set the tree and display it
        this->my_tree = &tree;
        display_tree();

        // Create buttons and text box
        text_box = new QTextEdit(main_window);
        text_box->setGeometry(QRect(QPoint(600, 0), QSize(screen_width - 600, 30)));
        text_box->setText("");
        text_box->show();

        bfs_button = new QPushButton("BFS", main_window);
        bfs_button->move(0, screen_height - 100);
        bfs_button->show();
        QObject::connect(bfs_button, &QPushButton::clicked, [&]()
        {
            string text = "";
            for (auto node = tree.begin_BFS(); node != tree.end_BFS(); ++node) {
                text.append(toQString(**node).toStdString() + " ");
            }
            text_box->setText(QString::fromStdString(text)); 
        });

        dfs_button = new QPushButton("DFS", main_window);
        dfs_button->move(100, screen_height - 100);
        dfs_button->show();
        QObject::connect(dfs_button, &QPushButton::clicked, [&]()
        {
            string text = "";
            for (auto node = tree.begin_DFS(); node != tree.end_DFS(); ++node) {
                text.append(toQString(**node).toStdString() + " ");
            }
            text_box->setText(QString::fromStdString(text)); 
        });

        pre_order_button = new QPushButton("Pre-Order", main_window);
        pre_order_button->move(200, screen_height - 100);
        pre_order_button->show();
        QObject::connect(pre_order_button, &QPushButton::clicked, [&]()
        {
            string text = "";
            for (auto node = tree.begin_PreOrder(); node != tree.end_PreOrder(); ++node) {
                text.append(toQString(**node).toStdString() + " ");
            }
            text_box->setText(QString::fromStdString(text)); 
        });

        in_order_button = new QPushButton("In-Order", main_window);
        in_order_button->move(300, screen_height - 100);
        in_order_button->show();
        QObject::connect(in_order_button, &QPushButton::clicked, [&]()
        {
            string text = "";
            for (auto node = tree.begin_InOrder(); node != tree.end_InOrder(); ++node) {
                text.append(toQString(**node).toStdString() + " ");
            }
            text_box->setText(QString::fromStdString(text)); 
        });

        post_order_button = new QPushButton("Post-Order", main_window);
        post_order_button->move(400, screen_height - 100);
        post_order_button->show();
        QObject::connect(post_order_button, &QPushButton::clicked, [&]()
        {
            string text = "";
            for (auto node = tree.begin_PostOrder(); node != tree.end_PostOrder(); ++node) {
                text.append(toQString(**node).toStdString() + " ");
            }
            text_box->setText(QString::fromStdString(text)); 
        });

        heap_button = new QPushButton("Heap", main_window);
        heap_button->move(500, screen_height - 100);
        heap_button->show();
        QObject::connect(heap_button, &QPushButton::clicked, [&]()
        {
            if (D != 2) {
                text_box->setText("Heap is only supported for binary trees.");
                return;
            }
            string text = "";
            for (auto node = tree.begin_Heap(); node != tree.end_Heap(); ++node) {
                text.append(toQString(**node).toStdString() + " ");
            }
            text_box->setText(QString::fromStdString(text));
            display_tree(); 
        });

        my_app->exec();
    }

private:
    /**
     * Displays the entire tree.
     */
    void display_tree();

    /**
     * Displays a single node and its children.
     */
    void display_node(typename Node<T>::Node *node, int x, int y, int left_border, int right_border);

    /**
     * Draws a node at specified coordinates.
     */
    QPointF draw_node(typename Node<T>::Node *node, int x, int y);
};

/**
 * Draws a node and returns its center position.
 */
template <typename T, unsigned int D>
QPointF Screen<T, D>::draw_node(typename Node<T>::Node *node, int x, int y)
{
    QGraphicsEllipseItem *ellipse = my_scene->addEllipse(x - NODE_RADIUS, y - NODE_RADIUS, 2 * NODE_RADIUS, 2 * NODE_RADIUS);
    QBrush brush(Qt::blue);
    QPen pen(Qt::black);
    ellipse->setBrush(brush);
    ellipse->setPen(pen);

    // Display node value as text
    QString text_string = toQString(node->get_value());
    QGraphicsTextItem *text = my_scene->addText(text_string);
    text->setDefaultTextColor(Qt::white);
    text->setPos(x - NODE_RADIUS / 2, y - NODE_RADIUS / 2);

    return ellipse->rect().center();
}

/**
 * Display the tree in a GUI window.
 */
template <typename T, unsigned int D>
Screen<T, D> display(Tree<T, D> &input_tree)
{
    return Screen<T, D>(input_tree);
}

/**
 * Clears the scene and starts the display process from the root.
 */
template <typename T, unsigned int D>
void Screen<T, D>::display_tree()
{
    my_scene->clear();
    if (my_tree->get_root() == nullptr)
        return;

    // Starting coordinates and spacing
    int root_X = screen_width / 2;
    int root_Y = 10 + NODE_RADIUS;

    display_node(my_tree->get_root(), root_X, root_Y, 0, screen_width);
}

/**
 * Recursively displays a node and its children.
 */
template <typename T, unsigned int D>
void Screen<T, D>::display_node(typename Node<T>::Node *node, int x, int y, int left_border, int right_border)
{
    QPointF curr_center = draw_node(node, x, y);

    for (unsigned int i = 0; i < node->num_children(); i++)
    {
        Node<T> *child = node->get_child(i);
        int child_X = (right_border - left_border) / (D + 1) * (i + 1) + left_border;
        int child_left_X = (right_border - left_border) / (D + 1) * (i) + left_border;
        int child_right_X = (right_border - left_border) / (D + 1) * (i + 2) + left_border;

        QPointF child_center = draw_node(child, child_X, y + VERTICAL_SPACING);
        my_scene->addLine(QLineF(curr_center, child_center));
        display_node(child, child_X, y + VERTICAL_SPACING,
                    child_left_X + NODE_RADIUS * 2.1, child_right_X - NODE_RADIUS * 2.1);
    }
}

} // namespace ariel

#endif // FRONTEND_HPP
