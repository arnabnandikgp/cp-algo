from kivy.app import App
from kivy.uix.button import Button
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.gridlayout import GridLayout
from kivy.uix.label import Label
from kivy.uix.popup import Popup
# from kivy.garden.matplotlib.backend_kivyagg import FigureCanvasKivyAgg
import matplotlib.pyplot as plt
import math
from kivy.core.window import Window
from kivy.uix.image import Image
from kivy.uix.behaviors import ButtonBehavior

# Set window size
Window.size = (400, 600)

class ImageButton(ButtonBehavior, Image):
    pass

class MyBoxLayout(BoxLayout):
    def __init__(self, **kwargs):
        super(MyBoxLayout, self).__init__(**kwargs)
        self.orientation = 'vertical'
        self.padding = 10
        self.spacing = 10

        background = Image(source='DSC08571.jpg', allow_stretch=True, keep_ratio=False)
        with self.canvas.before:
            self.bg_rect = background
            self.bind(size=self._update_bg, pos=self._update_bg)

        self.output_label = Label(size_hint_y=0.75, font_size=50, halign='right', valign='middle', text='',
                                  color=(0.2, 0.2, 0.2, 1))
        self.output_label.bind(size=self._update_label_text)

        button_symbols = ('1', '2', '3', '+',
                          '4', '5', '6', '-',
                          '7', '8', '9', '.',
                          '0', '*', '/', '=',
                          '(', ')', 'sqrt', 'floor',
                          'sin', 'cos', 'tan', 'plot')

        button_grid = GridLayout(cols=4, size_hint_y=2, spacing=5)

        for symbol in button_symbols:
            button = Button(text=symbol, font_size=32, background_normal='', background_color=(0.2, 0.6, 0.8, 1),
                            color=(1, 1, 1, 1), border=(16, 16, 16, 16))
            button.bind(on_press=self.print_button_text)
            button_grid.add_widget(button)

        clear_button = Button(text='Clear', size_hint_y=None, height=100, font_size=32, background_normal='',
                              background_color=(1, 0.4, 0.4, 1), color=(1, 1, 1, 1), border=(16, 16, 16, 16))
        clear_button.bind(on_press=self.clear_label)

        # Bind the equal button to evaluate_result and plot button to plot_graph
        for button in button_grid.children:
            if button.text == '=':
                button.bind(on_press=self.evaluate_result)
            elif button.text == 'plot':
                button.bind(on_press=self.plot_graph)

        self.add_widget(self.output_label)
        self.add_widget(button_grid)
        self.add_widget(clear_button)

    def _update_bg(self, instance, value):
        self.bg_rect.size = instance.size
        self.bg_rect.pos = instance.pos

    def _update_label_text(self, instance, value):
        instance.text_size = (instance.width - 20, None)
        instance.texture_update()
        instance.height = instance.texture_size[1]

    def print_button_text(self, instance):
        text = instance.text
        if text == 'sqrt':
            self.output_label.text += 'math.sqrt('
        elif text == 'floor':
            self.output_label.text += 'math.floor('
        elif text == 'sin':
            self.output_label.text += 'math.sin(math.radians('
        elif text == 'cos':
            self.output_label.text += 'math.cos(math.radians('
        elif text == 'tan':
            self.output_label.text += 'math.tan(math.radians('
        else:
            self.output_label.text += text

    def evaluate_result(self, instance):
        try:
            self.output_label.text = str(eval(self.output_label.text))
        except SyntaxError:
            self.output_label.text = 'Python Syntax error!'
        except Exception as e:
            self.output_label.text = str(e)

    def clear_label(self, instance):
        self.output_label.text = ""

    def plot_graph(self, instance):
        try:
            expr = self.output_label.text  # Get the expression from the label
            expr = expr.replace('math.', '')
            x = list(range(-360, 360))
            y = [eval(expr.replace('x', str(i))) for i in x]

            plt.clf()  # Clear the previous plot
            plt.plot(x, y)
            plt.xlabel('x')
            plt.ylabel('y')
            plt.title('Graph of ' + expr)
            plt.grid(True)

            plt_widget = FigureCanvasKivyAgg(plt.gcf())

            # Create a popup window to display the plot
            popup = Popup(title='Graph', content=plt_widget, size_hint=(0.9, 0.9))
            popup.open()

        except Exception as e:
            self.output_label.text = str(e)

class MyApp(App):
    def build(self):
        return MyBoxLayout()

if __name__ == '__main__':
    MyApp().run()