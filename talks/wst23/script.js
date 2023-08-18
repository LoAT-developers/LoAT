let {view, move, fade_in, fade_out, toggle_logo, invert, change_view, start, align_vertically, align_horizontally, set_color} = window.preji;

var title = view("title").set_scale(1.3);
var loat = view("loat").set_scale(1.1);
var svg = view("svg");
var adcl = view("adcl").set_scale(1.3);
var properties = view("properties").set_scale(1.3);
var formats = view("formats").set_scale(1.3);
var dependencies = view("dependencies").set_scale(1.3);
var future = view("future").set_scale(1.1);
var proofs = view("proofs").set_scale(1.1);
var counterexamples = view("counterexample").set_scale(1.5);
var free = view("free").set_scale(1.3);

var slides = [
    [fade_out(["counterexample"], duration=0)],
    [change_view(title, delay=0, slowdown=0)],
    [fade_out(["title-prefix"], val=0.2)],
    [change_view(svg)],
    [change_view(loat)],
    [change_view(properties)],
    [change_view(adcl)],
    [change_view(loat)],
    [change_view(formats)],
    [change_view(loat)],
    [change_view(proofs)],
    [change_view(counterexamples), fade_in(["counterexample"])],
    [change_view(loat)],
    [change_view(dependencies)],
    [change_view(loat)],
    [change_view(future)],
    [change_view(loat)],
    [change_view(free)],
    [change_view(svg)]
];

// start the presentation
start(slides);
