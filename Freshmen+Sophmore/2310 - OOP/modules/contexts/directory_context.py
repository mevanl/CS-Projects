import os
import requests
from dotenv import load_dotenv
from modules.contexts.context import Context
from requests.exceptions import HTTPError, ConnectionError
from modules.classifiers.common.intentclassifier import IntentClassifier
from modules.exceptions import URLUndefinedException, PreconditionException, ServiceUnavailableException, DirectoryNotFoundException
from modules.contexts.directory_entry import DirectoryEntry


class DirectoryContext(Context):
    def __init__(self, name: str, classifier: IntentClassifier):
        super().__init__(name, classifier)
        self.__entries: list = []
        self.__query: str = None

    @property
    def entries(self) -> list:
        return self.__entries

    @entries.setter
    def entries(self, ent: list):
        self.__entries = ent

    @property
    def query(self) -> str:
        return self.__query

    @query.setter
    def query(self, qu: str):
        self.__query = qu

    def get_directory_info(self):
        domain_url = os.getenv("DIRECTORY_SERVICE_URI")
        full_url = "{}apiKey={}&searchCriteria={}".format(domain_url, os.getenv("DIRECTORY_API_KEY"), self.query)
        data = None

        if not os.getenv("DIRECTORY_SERVICE_URI") == "https://portapi.tntech.edu/express/api/unprotected/getDirectoryInfoByAPIKey.php?":
            raise URLUndefinedException("DIRECTORY_SERVICE_URI is modified or empty.")

        if self.query == "":
            raise DirectoryNotFoundException("No query given.")
        if not self.query:
            raise PreconditionException("No query.")

        try:
            requestedData = requests.get(full_url)
            requestedData.raise_for_status()
            data = requestedData.json()

            if not data:
                raise Exception

            for d in data:
                self.entries.append(DirectoryEntry(d))

        except ConnectionError as ex:
            raise ServiceUnavailableException(ex)
        except Exception:
            if self.entries.__len__() == 0:
                raise DirectoryNotFoundException("Query not Found.")

    def __str__(self):
        data = ""
        for e in range(len(self.entries)):
            data = data + "\n\n" + self.entries[e].__str__()
        return data