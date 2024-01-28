class TsClass {
    private readonly name: string;
    private readonly age: number;

    public concantInfo(): string {
        return this.name.concat(this.age.toString());
    }
}


class JsClass {
    public lol(): void {
        console.log('lol js');
    }
}

class JavaClass {
    public lol(): void {
        console.log('lol java');
    }
}
