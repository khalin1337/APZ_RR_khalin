using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;

public class ReadersWritersLock
{
    private ReaderWriterLockSlim _lock = new ReaderWriterLockSlim();

    public void Read(Action readAction)
    {
        _lock.EnterReadLock();
        try
        {
            readAction();
        }
        finally
        {
            _lock.ExitReadLock();
        }
    }

    public void Write(Action writeAction)
    {
        _lock.EnterWriteLock();
        try
        {
            writeAction();
        }
        finally
        {
            _lock.ExitWriteLock();
        }
    }
}

// Usage
class Program
{
    static void Main(string[] args)
    {
        var rwLock = new ReadersWritersLock();
        var data = new List<int> { 1, 2, 3, 4, 5 };

        // Reader tasks
        Task.Run(() => rwLock.Read(() => {
            Console.WriteLine("Reading data: " + string.Join(", ", data));
        }));

        // Writer task
        Task.Run(() => rwLock.Write(() => {
            data.Add(6);
            Console.WriteLine("Data written");
        })).Wait();

        // Ensure the read task has completed
        Thread.Sleep(1000);
    }
}
