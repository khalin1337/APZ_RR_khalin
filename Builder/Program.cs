// Product class
public class Product
{
    public string PartA { get; set; }
    public string PartB { get; set; }
}

// Abstract Builder
public abstract class Builder
{
    public abstract void BuildPartA();
    public abstract void BuildPartB();
    public abstract Product GetResult();
}

// Concrete Builder
public class ConcreteBuilder : Builder
{
    private Product product = new Product();

    public override void BuildPartA()
    {
        product.PartA = "PartA";
    }

    public override void BuildPartB()
    {
        product.PartB = "PartB";
    }

    public override Product GetResult()
    {
        return product;
    }
}

// Director
public class Director
{
    public void Construct(Builder builder)
    {
        builder.BuildPartA();
        builder.BuildPartB();
    }
}

// Usage
class Program
{
    static void Main(string[] args)
    {
        Builder builder = new ConcreteBuilder();
        Director director = new Director();
        director.Construct(builder);
        Product product = builder.GetResult();
        Console.WriteLine($"Product parts: {product.PartA}, {product.PartB}");
    }
}
