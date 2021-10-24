using System.Runtime.InteropServices;

namespace BlazorWebAssemblyDemos
{
    public abstract class NativeObject : IDisposable
    {
        protected NativeObject(nint handle)
        {
            Handle = handle;
        }

        public nint Handle { get; private set; }

        protected abstract void Dispose(bool disposing);

        protected static nint GetStateFromDelegate(Delegate del, out GCHandle callbackHandle)
        {
            callbackHandle = GCHandle.Alloc(del);
            var state = (nint)callbackHandle;
            return state;
        }

        protected static T? GetDelegateFromState<T>(nint state)
            where T : Delegate
        {
            var callbackHandle = GCHandle.FromIntPtr(state);
            var callback = (T?)callbackHandle.Target;
            return callback;
        }

        ~NativeObject() =>
            DoDispose(disposing: false);

        public void Dispose()
        {
            DoDispose(disposing: true);
            GC.SuppressFinalize(this);
        }

        void DoDispose(bool disposing)
        {
            if (Handle == 0)
                return;

            Dispose(disposing);

            Handle = 0;
        }
    }
}
