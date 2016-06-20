#encoding "utf8"

NotebookWord -> Word<kwtype="ноутбук_слово">;

NotebookVendorRus -> Word<kwtype="ноутбук_производитель_рус">;
NotebookVendorEng -> Word<kwtype="ноутбук_производитель_англ">;
NotebookVendor -> NotebookVendorRus | NotebookVendorEng;

NotebookModel -> UnknownPOS* AnyWord<wff=/\w\d/>;

NotebookUserDefinedName -> AnyWord<kwtype="ноутбук_пользовательское_название">;

NotebookNumberInPrice -> AnyWord<wff=/\d{1,2}/>;

S -> NotebookWord interp(Notebook.Word) (NotebookVendor interp(Notebook.Vendor)) (NotebookModel interp(Notebook.Model));
S -> (NotebookWord interp(Notebook.Word)) NotebookVendor interp(Notebook.Vendor) (NotebookModel interp(Notebook.Model));
S -> NotebookUserDefinedName interp(Notebook.UserDefinedName);
S -> NotebookWord interp(Notebook.Word) NotebookNumberInPrice interp(NotebookFromPrice.NumberInPrice);