namespace BlazorWebAssemblyDemos
{
    // BUG: https://github.com/dotnet/runtime/issues/60802
    // Loads of extra code here to workaround (at least my understanding) a bug using new things
    [AttributeUsage(AttributeTargets.Method)]
    internal sealed class MonoPInvokeCallbackAttribute : Attribute
    {
        public MonoPInvokeCallbackAttribute(Type type)
        {
            Type = type;
        }

        public Type Type { get; private set; }
    }
}
