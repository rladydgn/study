from time import timezone

from django.http import HttpResponseRedirect
from django.shortcuts import render, HttpResponse, get_object_or_404
from django.template import loader
from django.urls import reverse
from django.views import generic

from poll.models import Question, Choice


# def index(request):
    # latest_question_list = Question.objects.order_by('-pub_date')[:5]
    # output = ', '.join([q.question_text for q in latest_question_list])
    # return HttpResponse(output)

    # template = loader.get_template('poll/index.html')
    # context = {
    #     'latest_question_list': latest_question_list,
    # }
    # return HttpResponse(template.render(context, request))

    # context = {
    #     'latest_question_list': latest_question_list,
    # }

    # HttpResponse 객체 반환
    # return render(request, 'poll/index.html', context)


class IndexView(generic.ListView):
    template_name = 'poll/index.html'
    # index.html 에 넘어가는 이름?
    context_object_name = 'latest_question_list'

    def get_queryset(self):
        return Question.objects.filter(pub_date__lte=timezone.now()).order_by('-pub_data')[:5]


# 호출시 question id 리턴
# def detail(request, question_id):
    # return HttpResponse(f"You are looking at question {question_id}")
    # 객체 내부 속성 확인
    # print(request.__dict__)

    # pk에 해당하는 data 가 question table에 없다면 404 예외가 발생한다.
    # question = get_object_or_404(Question, pk=question_id)
    # return render(request, 'poll/detail.html', {'question': question})

class DetailView(generic.DetailView):
    # url 에서 들어온 기본 키 값을 pk 라고 기대한다.
    model = Question
    template_name = 'poll/detail.html'

    def get_queryset(self):
        """
        Excludes any questions that aren't published yet.
        """
        return Question.objects.filter(pub_date__lte=timezone.now())


# 호출시 question id 리턴
# def results(request, question_id):
    # return HttpResponse(f"you are looking at the results of question {question_id}")

    # question = get_object_or_404(Question, pk=question_id)
    # return render(request, 'poll/results.html', {'question': question})

class ResultsView(generic.DetailView):
    model = Question
    template_name = 'poll/results.html'


# 호출시 question id 리턴
def vote(request, question_id):
    # return HttpResponse(f"you are voting on question {question_id}")

    question = get_object_or_404(Question, pk=question_id)
    try:
        selected_choice = question.choice_set.get(pk=request.POST['choice'])
    except (KeyError, Choice.DoesNotExist):
        return render(request, 'poll/detail.html', {
            'question': question,
            'error_message': "you didn't select a choice.",
        })
    else:
        selected_choice.votes += 1
        selected_choice.save()
        # POST 데이터를 성공적으로 처리한 후에는 항상 이렇게 반환해야 함. 일반적으로 좋은 웹 개발 관행.
        return HttpResponseRedirect(reverse('poll:results', args=(question_id,)))
