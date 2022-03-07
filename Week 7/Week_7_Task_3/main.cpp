#include "Header.h"

int main() {

     enum months{Jan=10, Apr=30, Jun=20,Sep=50, Nov=30};
    Extended_queue Fifo;
    Stack Lifo;
    const int stocks = 100;
    int sum_fifo, sum_lifo, month_sum, temp;

    //January  buying
    month_sum = stocks*Jan;
    cout << "Sum, January:" << month_sum << "\n";
    Fifo.append(month_sum);
    Lifo.push(month_sum);

    //April buying
    month_sum = stocks*Apr;
    cout << "Sum, April:" << month_sum << "\n";
    Fifo.append(month_sum);
    Lifo.push(month_sum);

    // June, selling
    month_sum = stocks*Jun;
    cout << "Sum, June:" << month_sum << "\n";
    Fifo.serve_and_retrieve(sum_fifo);
    Lifo.top(sum_lifo);
    Lifo.pop();
    sum_fifo -= month_sum;
    sum_lifo -= month_sum;

    // September, purchasing
    month_sum = stocks*Sep;
    cout << "Sum, September:" << month_sum << "\n";
    Fifo.append(month_sum);
    Lifo.push(month_sum);

    //November, selling
    month_sum = stocks*Nov;
    cout << "Sum, November:" << month_sum << "\n";
    Fifo.serve_and_retrieve(temp);
    temp-=month_sum;
    sum_fifo += temp;

    Lifo.top(temp);
    temp-=month_sum;
    sum_lifo+=temp;

    cout << "Total gain(-) or loss(+) is:\n"
         << "With FIFO accounting: " << sum_fifo << "\n"
         << "With LIFO accounting: " << sum_lifo << "\n";

    return 0;
}
