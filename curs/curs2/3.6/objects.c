#include "objects.h"

// NAME

const char *get_name_circle(const object_t *fig) { return "Circle"; }
const char *get_name_triangle(const object_t *fig) { return "Triangle"; }
const char *get_name_rectangle(const object_t *fig) { return "Rectangle"; }

// SHOW DATA

void show_data_circle(const object_t *fig) {
  printf("Radius: %f\n", fig->circle.radius);
}

void show_data_triangle(const object_t *fig) {
  printf("Sides: %f, %f, %f\n", fig->triangle.a, fig->triangle.b,
         fig->triangle.c);
}

void show_data_rectangle(const object_t *fig) {
  printf("Length: %f, Width: %f\n", fig->rectangle.length,
         fig->rectangle.width);
}

// PERIMETER

double get_perimeter_circle(const object_t *fig) {
  return 2 * PI * fig->circle.radius;
}

double get_perimeter_triangle(const object_t *fig) {
  return fig->triangle.a + fig->triangle.b + fig->triangle.c;
}

double get_perimeter_rectangle(const object_t *fig) {
  return 2 * (fig->rectangle.length + fig->rectangle.width);
}

// AREA

double get_area_circle(const object_t *fig) {
  return PI * fig->circle.radius * fig->circle.radius;
}

double get_area_triangle(const object_t *fig) {
  double p = (fig->triangle.a + fig->triangle.b + fig->triangle.c) / 2;
  return sqrt(p * (p - fig->triangle.a) * (p - fig->triangle.b) *
              (p - fig->triangle.c));
}

double get_area_rectangle(const object_t *fig) {
  return fig->rectangle.length * fig->rectangle.width;
}

// CONSTUCTORS

void *alloc(size_t bytes) {
  void *p = malloc(bytes);

  if (p == NULL) {
    perror("Memory allocation error");
    exit(1);
  }

  return p;
}

object_t *circle_constructor(double radius) {
  object_t *circle = (object_t *)alloc(sizeof(object_t));

  circle->type = CIRCLE;
  circle->circle.radius = radius;
  circle->methods.get_area = get_area_circle;
  circle->methods.get_perimeter = get_perimeter_circle;
  circle->methods.get_name = get_name_circle;
  circle->methods.show_data = show_data_circle;

  return circle;
}

object_t *triangle_constructor(double a, double b, double c) {
  object_t *triangle = (object_t *)alloc(sizeof(object_t));

  triangle->type = TRIANGLE;
  triangle->triangle.a = a;
  triangle->triangle.b = b;
  triangle->triangle.c = c;
  triangle->methods.get_area = get_area_triangle;
  triangle->methods.get_perimeter = get_perimeter_triangle;
  triangle->methods.get_name = get_name_triangle;
  triangle->methods.show_data = show_data_triangle;

  return triangle;
}

object_t *rectangle_constructor(double length, double width) {
  object_t *rectangle = (object_t *)alloc(sizeof(object_t));

  rectangle->type = RECTANGLE;
  rectangle->rectangle.length = length;
  rectangle->rectangle.width = width;
  rectangle->methods.get_area = get_area_rectangle;
  rectangle->methods.get_perimeter = get_perimeter_rectangle;
  rectangle->methods.get_name = get_name_rectangle;
  rectangle->methods.show_data = show_data_rectangle;

  return rectangle;
}

factory_t init_factory(void) {
  return (factory_t){
      circle_constructor,
      rectangle_constructor,
      triangle_constructor,
  };
}
