from django.shortcuts import render, HttpResponse, get_object_or_404
from django.template import loader

from poll.models import Question


def index(request):
    latest_question_list = Question.objects.order_by('-pub_date')[:5]
    # output = ', '.join([q.question_text for q in latest_question_list])
    # return HttpResponse(output)

    # template = loader.get_template('poll/index.html')
    # context = {
    #     'latest_question_list': latest_question_list,
    # }
    # return HttpResponse(template.render(context, request))

    context = {
        'latest_question_list': latest_question_list,
    }

    # HttpResponse 객체 반환
    return render(request, 'poll/index.html', context)


# 호출시 question id 리턴
def detail(request, question_id):
    # return HttpResponse(f"You are looking at question {question_id}")
    # 객체 내부 속성 확인
    # print(request.__dict__)

    # pk에 해당하는 data 가 question table에 없다면 404 예외가 발생한다.
    question = get_object_or_404(Question, pk=question_id)
    return render(request, 'poll/detail.html', {'question': question})


# 호출시 question id 리턴
def results(request, question_id):
    return HttpResponse(f"you are looking at the results of question {question_id}")


# 호출시 question id 리턴
def vote(request, question_id):
    return HttpResponse(f"you are voting on question {question_id}")
