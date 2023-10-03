import win32com.client as win32

# Open the Word application
word_app = win32.gencache.EnsureDispatch("Word.Application")

# Open the Word document
doc = word_app.Documents.Open(r"path\to\your\document.docx")

# Loop through each page and save as PDF
for page_number in range(1, doc.ComputeStatistics(2)):  # Total number of pages
    page_range = doc.GoTo(win32.constants.wdGoToPage, win32.constants.wdGoToAbsolute, page_number)
    page_range.Select()
    pdf_filename = f"page_{page_number}.pdf"
    doc.ExportAsFixedFormat(pdf_filename, win32.constants.wdExportFormatPDF)

# Close the document and Word application
doc.Close()
word_app.Quit()
