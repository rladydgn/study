from rest_framework import permissions


class CustomReadOnly(permissions.BasePermission):
    # 조회 : 아무나, 생성 : 로그인한 사람만
    def has_permission(self, request, view):
        if request.method == 'GET':
            return True
        return request.user.is_authenticated

    # 수정 : 글 작성자만
    def has_object_permission(self, request, view, obj):
        # 데이터에 영향을 미치지 않는 메서드는 True 리턴, ex) GET
        if request.method in permissions.SAFE_METHODS:
            return True
        # 작성 글 저자(post 모델) == 수정 요청자 저자(user pk?)
        return obj.author == request.user
