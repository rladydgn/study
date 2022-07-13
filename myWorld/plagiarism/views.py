from django.http import HttpResponse
from django.shortcuts import render
from django.views import generic

import random


# def index(request):
#    return HttpResponse("hello world!")


class IndexView(generic.TemplateView):
    template_name = "plagiarism/index.html"

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['number'] = random.randrange(1, 100)
        return context
