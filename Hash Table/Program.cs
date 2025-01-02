using System;
namespace MyCSharpApp
{
    class Program
    {
        static int x = 0;
        static void Main(string[] args)
        {
            int x ;
            x = fun(5);
            Console.WriteLine(x);

        }
        static int fun(int n)
        {
            if(n < 0 )
            {
                x++;
                return fun(n-1) + x;
            }
            return 0;
        }
    }
}