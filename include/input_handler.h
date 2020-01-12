#ifndef INPUT_HANDLER_H_
#define INPUT_HANDLER_H_

class Command;
class InputHandler {
 public:
    InputHandler();
    ~InputHandler();
    Command* handleInput() const;

 private:
    Command* key_enter_;
    Command* key_esc_;
    Command* key_left_;
    Command* key_right_;
};
#endif  // INPUT_HANDLER_H_
