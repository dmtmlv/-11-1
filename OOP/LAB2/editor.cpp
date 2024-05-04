#include <iostream>
#include <stack>
#include <string>

// интерфейс
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// команда для ввода символа
class TypeCommand : public Command {
private:
    std::string& buffer;
    char typedChar;
    int cursorPos;

public:
    TypeCommand(std::string& buf, char c, int pos) : buffer(buf), typedChar(c), cursorPos(pos) {}

    void execute() override {
        buffer.insert(cursorPos, 1, typedChar);
        cursorPos++;
    }

    void undo() override {
        buffer.erase(cursorPos - 1, 1);
        cursorPos--;
    }
};

// команда для перемещения курсора влево
class ShiftLeftCommand : public Command {
private:
    int& cursorPos;

public:
    ShiftLeftCommand(int& pos) : cursorPos(pos) {}

    void execute() override {
        cursorPos = std::max(0, cursorPos - 1);
    }

    void undo() override {
        cursorPos++;
    }
};

// команда для перемещения курсора вправо
class ShiftRightCommand : public Command {
private:
    int& cursorPos;
    int bufferSize;

public:
    ShiftRightCommand(int& pos, int bufSize) : cursorPos(pos), bufferSize(bufSize) {}

    void execute() override {
        cursorPos = std::min(bufferSize, cursorPos + 1);
    }

    void undo() override {
        cursorPos--;
    }
};

// класс TextEditor
class TextEditor {
private:
    std::string buffer;
    int cursorPos;
    std::stack<Command*> history;
    std::stack<Command*> redoHistory;

public:
    TextEditor() : cursorPos(0) {}

    void Type(char c) {
        Command* command = new TypeCommand(buffer, c, cursorPos);
        command->execute();
        history.push(command);
    }

    void ShiftLeft() {
        Command* command = new ShiftLeftCommand(cursorPos);
        command->execute();
        history.push(command);
    }

    void ShiftRight() {
        Command* command = new ShiftRightCommand(cursorPos, buffer.size());
        command->execute();
        history.push(command);
    }

    void Backspace() {
        if (cursorPos > 0) {
            buffer.erase(cursorPos - 1, 1);
            cursorPos--;
        }
    }

    void Undo() {
        if (!history.empty()) {
            Command* command = history.top();
            history.pop();
            command->undo();
            redoHistory.push(command);
        }
    }

    void Redo() {
        if (!redoHistory.empty()) {
            Command* command = redoHistory.top();
            redoHistory.pop();
            command->execute();
            history.push(command);
        }
    }

    const std::string& GetText() const {
        return buffer;
    }
};

int main() {
    TextEditor editor;

    editor.Type('o');
    editor.Type('l');
    editor.Type('l');
    editor.Type('e');
    editor.Type('H');
    editor.ShiftLeft();
    editor.Backspace();
    editor.Undo();
    editor.Redo();

    std::cout << editor.GetText() << std::endl;

    return 0;
}

```cpp
int main()```
