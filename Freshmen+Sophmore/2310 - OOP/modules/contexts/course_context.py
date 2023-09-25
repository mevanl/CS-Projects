import os
import requests
from dotenv import load_dotenv
from modules.contexts.context import Context
from requests.exceptions import HTTPError, ConnectionError, MissingSchema
from modules.classifiers.common.intentclassifier import IntentClassifier
from modules.exceptions import URLUndefinedException, CourseNotFoundException, PreconditionException, ServiceUnavailableException


class CourseContext(Context):
    def __init__(self, name: str, classifier: IntentClassifier):
        super().__init__(name, classifier)
        self.__subject: str = None
        self.__course: str = None
        self.__description: str = None
        self.__title: str = None
        self.__prerequisites: list = []

    @property
    def subject(self) -> str:
        return self.__subject

    @subject.setter
    def subject(self, sub: subject):
        self.__subject = sub

    @property
    def course(self) -> str:
        return self.__course

    @course.setter
    def course(self, c: course):
        self.__course = c
    @property
    def description(self) -> str:
        return self.__description

    @description.setter
    def description(self, d: description):
        self.__description = d
    @property
    def title(self) -> str:
        return self.__title

    @title.setter
    def title(self, t):
        self.__title = t

    @property
    def prerequisites(self) -> str:
        return self.__prerequisites

    @prerequisites.setter
    def prerequisites(self, pre: prerequisites):
        self.__prerequisites = pre

    def get_course_info(self) -> None:
        domain_url = os.getenv("COURSE_SERVICE_URI")
        full_url = "{}subject={}&number={}&term={}".format(domain_url, self.subject, self.course, "202280")

        if not os.getenv("COURSE_SERVICE_URI") == "http://csclnx01.tntech.edu:8080/courses?":
            if os.getenv("COURSE_SERVICE_URI") == "":
                raise URLUndefinedException("COURSE_SERVICE_URI is empty")
            else:
                raise ServiceUnavailableException("Unable to connect\nURI is bad.")

        try:
            requestedData = requests.get(full_url)
            requestedData.raise_for_status()
            data = requestedData.json()

            self.description = data["attribute"]["description"]
            self.title = data["attribute"]["title"]
            self.prerequisites = data["attribute"]["prerequisites"]
        except ConnectionError as ex:
            raise ServiceUnavailableException(ex)
        except Exception:
            if not self.course and not self.subject:
                raise PreconditionException("Specify Subject and Course\nsubject: {}, course: {}.".format(self.subject, self.course))
            if not self.course or not self.subject:
                if not self.course:
                    raise PreconditionException("Specify Subject\nSubject: {}.".format(self.subject))
                else:
                    raise PreconditionException("Specify Course\nCourse: {}.".format(self.course))
            if data["attribute"] is None:
                raise CourseNotFoundException("For subject: {}, course: {}.".format(self.subject, self.course))

    def __str__(self):
        return "{}\n{}\n{}".format(self.title, self.description, self.prerequisites)
