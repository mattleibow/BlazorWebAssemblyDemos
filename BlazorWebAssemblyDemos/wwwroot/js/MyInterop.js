
export class MyInterop {

    static showAlert(args) {
        // "process" the text in js
        let msg =
            `Message: '${args.message}'\n` +
            `Number: ${args.number}`;

        // show a simple dialog
        alert(msg);
    }

    static requestGlobal() {
        // ask the user for text
        let input = prompt("Enter some text:");

        // pass it to .NET
        DotNet
            .invokeMethodAsync('BlazorWebAssemblyDemos', 'ProcessInputAsync', input)
            .then((result) => {
                // show the results from .NET
                alert(result);
            });
    }

    static requestInstance(ref) {
        // ask the user for text
        let input = prompt("Enter some text:");

        // pass it to .NET
        ref.invokeMethodAsync('ProcessInputAsync', input);
    }

}
