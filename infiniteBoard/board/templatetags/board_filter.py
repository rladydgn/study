from django import template

register = template.Library()


@register.filter
def rest(value, arg):
    value -= 1
    return value - (value % arg)


@register.filter
def get_low(value, arg):
    value = (value-1) // arg
    start = value * arg + 1
    return start


@register.filter
def get_high(value, arg):
    value = (value-1) // arg
    end = (value + 1) * arg
    return end


@register.filter
def divide(value, arg):
    return (value-1) // arg


@register.filter
def next_chapter(value, arg):
    value = (value - 1) // arg
    return (value + 1) * arg + 1