# Intro to Dash

Dash is a powerful tool for building and deploying web applications (apps). It 
is based on plotly and enables great tools for visualization and analytics. 

## Main Blocks

The core idea behind dash is based on the interplay of three building blocks:

1) Components: These are all the things we see and interact with in the app.
Examples include drop-down menus, titles, sliders, and figures. 

2) Layout: This determines all the visual aspects of the app. In other words, here
we decide the look and feel of our project. 

3) CallBack: The callback is what enables the previous two components to communicate
and interact with each other. 
Without this feature we have a static interface which is not very useful to display
any information.

### Components

Components are created and sometimes initialized with some values. Usually however, 
if we want to provide some interesting functionality, we must make these components 
interact with each other. In fact, some components are initially empty, and
are expected to obtain some input from the callback function. 

### Layout
 
The layout is basically a container that will store and display all our components.
Additionally, it provides functionality to move and resize them, as well as enabling 
our visualization to be better organized. 

### The callback
This is perhaps the most defining and critical component of Dash. It enables for 
interaction through an input - output framework. In other words, the call back 
(formulated through a decorator) is a function that takes in some input from some 
components and provides output to other components! 

## Components

This section discusses some important components in Dash

### Markdown component 
This component enables writing text in markdown style. The usage is as follows:
```python
from dash import Dash, dcc # dash core components
import dash_bootstrap_components as dbc # components for layout

# Start Dash App
app = Dash(__name__, external_stylesheets=[dbc.themes.BOOTSTRAP])

# Instantiate a component
my_title = dcc.Markdown(children = "# My title")

# Add layout - here we add all components and possibly customize them
app.layout = dbc.Container([my_title])

if __name__ == "__main__":
    app.run_server(port = 8051)
```
In the example above, we added a markdown component which simply writes
"My title" as a header.

In the future we will leave out the initialization and library calls from the code
snippets and assume that those are also included. 

### Input component
This component enables interaction with the user so that they may enter a string
which acts as input text. 

```python
# Adding this will create a "widget" on the app where you
# type text
my_input = dcc.Input(value="my_input")
```

Later we will show examples where these components interact with each other.

### Dropdown component
This component creates a dropdown menu so that the user may interact with the 
visualizations. 
```python
my_dropdown_menu = dcc.Dropdown(
# Here we list all the options we can choose from
options = ["option1", "option2"],

# This is the initial value that the dropdown menu
# will have when the app is started
value = "option2",

# Whether the dropdown menu can contain nothing
clearable = False
)
```

### Graph component
This component adds graphs, which is the medium through which we will want to 
display our data. This can be anything from bar and pie charts, scatter plots, etc.
This is initially empty. Through the callback procedure, we will later pass a figure 
object to this component, so that it may add it to the app. 

```python
my_graph = dcc.Graph(figure = {})
```

### A quick example
Below we show an easy example for some small application
```python
from dash import Dash, dcc, Output, Input
import dash_bootstrap_components as dbc 

title = dcc.Markdown(children='# My first visualization in Dash')
graph = dcc.Graph(figure={})
dropdown_menu = dcc.Dropdown(
options=['Bar Plot', 'Scatter Plot'],
value='Bar Plot',  
clearable=False
)

app.layout = dbc.Container([title, graph, dropdown_menu])

@app.callback(
    Output(graph, component_property='figure'),
    Input(dropdown, component_property='value')
)
def update_graph(user_input):  # function arguments come from the component property of the Input
    if user_input == 'Bar Plot':
        fig = px.bar(data_frame=df, x="nation", y="count", color="medal")

    elif user_input == 'Scatter Plot':
        fig = px.scatter(data_frame=df, x="count", y="nation", color="medal",
                         symbol="medal")

    return fig
```
Let's analyze what is happening here: We created a title, a graph (initially empty), 
and a dropdown menu, from which we can select either "Bar Plot" or "Scatter Plot". 

We then added all these components in the container which will define the basic 
layout of our application. 

Finally, we have a function that will update the graph and is decorated by callback
to enable interaction between components. 
The decorator requires some inputs, which in our case is simply the value from the 
dropdown menu. Then, it also needs some outputs, which will be passed to the "figure" 
property of the "Graph" component.
The function itself is very simple, given the input, create a bar plot or a scatter 
plot and then return it!


